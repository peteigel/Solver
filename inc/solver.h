#ifndef inc_solver
#define inc_solver
#include "sudoku.h"
#include <tuple>

namespace sudoku {
	namespace solver {
		enum solver_result {success, hung, invalid, undefined};

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
		std::tuple<Puzzle<n>, solver_result, int> solve (Puzzle<n> puzzle, bool exhaustive);

		template <size_t n, typename queue_t>
		void add_guesses (const Puzzle<n>& puzzle, queue_t& queue);
	}
}

#endif
