#include "solver.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <deque>

using namespace std;
using namespace sudoku;

auto compare_iterators = [](auto it_a, auto it_b) -> bool {
	return &(*it_a) == &(*it_b);
};


auto count_solved = [](auto&& puzzle) -> int {
	return count_if(begin(puzzle.access()), end(puzzle.access()), [](auto& cell) -> bool {
		return cell.value() != 0;
	});
};

auto find_candidate = [](auto& puzzle) -> tuple<bool, size_t, size_t> {
	for (int n = 2; n < solver::max_branch; n++) {
		for (size_t row = 0; row < puzzle.max_val(); row++) {
			for (size_t col = 0; col < puzzle.max_val(); col++) {
				if (puzzle.access(row, col).num_possible() == n) {
					return make_tuple(true, row, col);
				}
			}
		}
	}

	return make_tuple(false, 0, 0);
};

template <size_t n>
void printPuzzle (Puzzle<n> puz) {
	for (size_t row = 0; row < puz.max_val(); row++) {
		for (size_t col = 0; col < puz.max_val(); col++) {
			cout << puz.access(row, col).value();
		}
		cout << '\n';
	}
    cout << '\n';
};

template <size_t n>
tuple<Puzzle<n>, solver::solver_result, int> solver::solve (Puzzle<n> puzzle, bool exhaustive) {
	deque<Puzzle<n>> queue;
	queue.push_front(puzzle);
	int num_solutions = 0;
	solver::solver_result best_result = solver::hung;
	Puzzle<n> solution;

	while (!queue.empty() && (num_solutions == 0 || exhaustive )) {
		auto currentGuess = queue.front();
		queue.pop_front();
		auto guess_result = solver::try_solve(currentGuess);
		if (guess_result == solver::hung) {
			solver::add_guesses(currentGuess, queue);
		} else if (guess_result < best_result) {
			best_result = guess_result;
			solution = currentGuess;
		}

		if (guess_result == solver::success) {
			num_solutions++;
			//printPuzzle(currentGuess);
		}
	}

	return make_tuple(solution, best_result, num_solutions);
}

template <size_t n, typename queue_t>
void solver::add_guesses (const Puzzle<n>& puzzle, queue_t& queue) {
	auto candidate_cell = find_candidate(puzzle);

	if (get<0>(candidate_cell)) {
		for (int val = 1; val <= puzzle.max_val(); val++) {
			if (puzzle.access(get<1>(candidate_cell), get<2>(candidate_cell)).access(val)) {
				//cout << "guess(" << get<1>(candidate_cell) << ", " << get<2>(candidate_cell) << ") -> " << val << '\n';
				queue.push_front(puzzle);
				queue.front().access(get<1>(candidate_cell), get<2>(candidate_cell)).set_value(val);
			}
		}
	}
}

template <size_t n>
solver::solver_result solver::try_solve (Puzzle<n>& puzzle) {
	try {
		while (solver::pass(puzzle) > 0);
	} catch (invalid_puzzle) {
		return solver::solver_result::invalid;
	}

	if (count_solved(puzzle) == puzzle.n_cells()) return solver::solver_result::success;
	else return solver::solver_result::hung;
}

template <size_t n>
int solver::pass (Puzzle<n>& puzzle) {
	auto init_cells_solved = count_solved(puzzle);
	solver::deduce_values(puzzle);
	solver::induce_values(puzzle);

	return count_solved(puzzle) - init_cells_solved;
}

template <size_t n>
void solver::induce_values (Puzzle<n>& puzzle) {
	for (int g = 0; g < puzzle.max_val() * 3; g++) {
		auto group = puzzle.group(g);

		for (int val = 1; val <= puzzle.max_val(); val++) {
			auto can_be_val = [val](auto cell_ptr) -> bool {
				return cell_ptr->access(val);
			};

			auto first_cell = find_if(begin(group), end(group), can_be_val);

			if (first_cell == end(group)) {
				throw invalid_puzzle("No possible candidate cell for value in group");
			}

			if (compare_iterators(first_cell, find_if(rbegin(group), rend(group), can_be_val))) {
				(*first_cell)->set_value(val);
			}
		}
	}
}

template <size_t n>
void solver::deduce_values (Puzzle<n>& puzzle) {
	for (int g = 0; g < puzzle.max_val() * 3; g++) {
		auto group = puzzle.group(g);
		for (auto&& cell1 : group) {
			auto val = cell1->value();

			if (val != 0) {
				for (auto&& cell2: group) {
					if (cell2 != cell1) {
						cell2->access(val) = false;
					}
				}
			}
		}
	}
}

namespace sudoku {
	namespace solver {
		template tuple<Puzzle<2>, solver::solver_result, int> solver::solve<2> (Puzzle<2> puzzle, bool exhaustive);
		template tuple<Puzzle<3>, solver::solver_result, int> solver::solve<3> (Puzzle<3> puzzle, bool exhaustive);
		template tuple<Puzzle<4>, solver::solver_result, int> solver::solve<4> (Puzzle<4> puzzle, bool exhaustive);
	}
}
