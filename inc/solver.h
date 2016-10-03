#ifndef inc_solver
#define inc_solver
#include "sudoku.h"

namespace sudoku {
	namespace solver {
		template <int n>
		int induceValues (*Puzzle<n> puzzle);

		template <int n>
		int deduceValues (*Puzzle<n> puzzle);

		template <int n>
		int pass (*Puzzle<n> puzzle);
	}
}

#endif
