#ifndef inc_sudoku_io
#define inc_sudoku_io
#include <iostream>
#include "sudoku.h"

namespace sudoku {
	namespace io {
		extern std::ostream* log;

		inline void enable_logging (std::ostream& stream) { log = &stream; };
		inline void enable_logging () { log = &std::cout; };
		inline void disable_logging () { log = nullptr; };

		template <std::size_t n>
		void pretty_print (Puzzle<n> puzzle, std::ostream& stream);

		template <std::size_t n>
		void pretty_print (Puzzle<n> puzzle) { pretty_print(puzzle, std::cout); };
	}
}

#endif
