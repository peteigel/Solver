#ifndef inc_sudoku_solver
#define inc_sudoku_solver
#include <tuple>
#include <iostream>
#include "sudoku.h"
#include "sudoku/io.h"

namespace sudoku {
	namespace solver {

		enum solver_result {success, invalid, hung};

		template <int n>
		struct solve_info {
			solver_result result = hung;
			int num_solutions = 0;
			int num_branches = 0;
			Puzzle<n> solution;
		};

		const int max_branch = 4;

		template <std::size_t n>
		void induce_values (Puzzle<n>& puzzle);

		template <std::size_t n>
		void deduce_values (Puzzle<n>& puzzle);

		template <std::size_t n>
		int pass (Puzzle<n>& puzzle);

		template <std::size_t n>
		solver_result try_solve (Puzzle<n>& puzzle);

		template <size_t n>
		solve_info<n> solve (Puzzle<n> puzzle, bool exhaustive);

		template <size_t n, typename queue_t>
		int add_guesses (const Puzzle<n>& puzzle, queue_t& queue);
	}
}

#endif
