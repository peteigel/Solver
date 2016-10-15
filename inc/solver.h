#ifndef inc_solver
#define inc_solver
#include "sudoku.h"

namespace sudoku {
	namespace solver {
		enum solver_result {success, hung, invalid};

		template <std::size_t n>
		void induce_values (Puzzle<n>& puzzle);

		template <std::size_t n>
		void deduce_values (Puzzle<n>& puzzle);

		template <std::size_t n>
		int pass (Puzzle<n>& puzzle);

		template <std::size_t n>
		solver_result try_solve (Puzzle<n>& puzzle);
	}
}

#endif
