#include "solver.h"
#include <algorithm>
#include <iterator>
#include <iostream>

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

template <size_t n> solver::solver_result solver::try_solve (Puzzle<n>& puzzle) {
	try {
		while (solver::pass(puzzle) > 0);
	} catch (invalid_puzzle) {
		return solver::solver_result::invalid;
	}

	if (count_solved(puzzle) == puzzle.n_cells()) return solver::solver_result::success;
	else return solver::solver_result::hung;
}

template <size_t n> int solver::pass (Puzzle<n>& puzzle) {
	auto init_cells_solved = count_solved(puzzle);
	solver::deduce_values(puzzle);
	solver::induce_values(puzzle);

	return count_solved(puzzle) - init_cells_solved;
}

template <size_t n> void solver::induce_values (Puzzle<n>& puzzle) {
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

template <size_t n> void solver::deduce_values (Puzzle<n>& puzzle) {
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
		template void induce_values<2> (Puzzle<2>& puzzle);
		template void induce_values<3> (Puzzle<3>& puzzle);
		template void induce_values<4> (Puzzle<4>& puzzle);
		template void deduce_values<2> (Puzzle<2>& puzzle);
		template void deduce_values<3> (Puzzle<3>& puzzle);
		template void deduce_values<4> (Puzzle<4>& puzzle);
		template int pass<2> (Puzzle<2>& puzzle);
		template int pass<3> (Puzzle<3>& puzzle);
		template int pass<4> (Puzzle<4>& puzzle);
		template solver_result try_solve<2> (Puzzle<2>& puzzle);
		template solver_result try_solve<3> (Puzzle<3>& puzzle);
		template solver_result try_solve<4> (Puzzle<4>& puzzle);
	}
}
