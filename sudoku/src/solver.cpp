#include "sudoku/solver.h"
#include <algorithm>
#include <iterator>
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
solver::solve_info<n> solver::solve (Puzzle<n> puzzle, bool exhaustive) {
	solve_info<n> result;
	deque<Puzzle<n>> queue;
	queue.push_front(puzzle);

	while (!queue.empty() && (result.num_solutions == 0 || exhaustive )) {
		auto currentGuess = queue.front();
		queue.pop_front();
		auto guess_result = solver::try_solve(currentGuess);
		if (guess_result == solver::hung) {
			result.num_branches += solver::add_guesses(currentGuess, queue);
		} else if (guess_result < result.result) {
			result.result = guess_result;
			result.solution = currentGuess;
		}

		if (guess_result == solver::success) {
			result.num_solutions++;
			if (io::log) {
				*io::log << "\nSolution Found:\n";
				io::pretty_print(currentGuess, *io::log);
			}
		}
	}

	return result;
}

template <size_t n, typename queue_t>
int solver::add_guesses (const Puzzle<n>& puzzle, queue_t& queue) {
	auto candidate_cell = find_candidate(puzzle);
	int branch_count = 0;

	if (get<0>(candidate_cell)) {
		for (int val = 1; val <= puzzle.max_val(); val++) {
			if (puzzle.access(get<1>(candidate_cell), get<2>(candidate_cell)).access(val)) {
				branch_count++;
				if (io::log) {
					*io::log << "guess(" << get<1>(candidate_cell) << ", " << get<2>(candidate_cell) << ") -> " << val << '\n';
				}
				queue.push_front(puzzle);
				queue.front().access(get<1>(candidate_cell), get<2>(candidate_cell)).set_value(val);
			}
		}
	}

	return branch_count;
}

template <size_t n>
solver::solver_result solver::try_solve (Puzzle<n>& puzzle) {
	try {
		while (solver::pass(puzzle) > 0);
	} catch (invalid_puzzle& e) {
		if (io::log) {
			*io::log << "No solution for this branch: " << e.what() << '\n';
		}
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
		template solve_info<2> solver::solve<2> (Puzzle<2> puzzle, bool exhaustive);
		template solve_info<3> solver::solve<3> (Puzzle<3> puzzle, bool exhaustive);
		template solve_info<4> solver::solve<4> (Puzzle<4> puzzle, bool exhaustive);
	}
}
