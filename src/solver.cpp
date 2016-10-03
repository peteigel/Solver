#include "solver.h"
#include <algorithm>
#include <iterator>
#include <stdexcept>

using namespace std;
using namespace sudoku;

template <int n> int solver::induceValues (Puzzle<n>* puzzle) {
	for (int g = 0; g < puzzle->max_val() * 3; g++) {
		auto group = puzzle->group(g);

		for (int val = 1; val <= puzzle->max_val(); val++) {
			auto can_be_val = [val](auto cell_ptr) -> bool {
				return cell_ptr->access(val);
			});

			auto first_cell = find(begin(group), end(group), can_be_val);

			if (first_cell == end(group)) {
				throw new logic_error("No possible candidate cell for value in group");
			}

			if (first_cell == find(reverse_iter(end(group)), begin(group), can_be_val)) {
				first_cell->set_value(val);
			}
		}
	}
}
