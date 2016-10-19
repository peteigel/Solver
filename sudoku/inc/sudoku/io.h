#ifndef inc_sudoku_io
#define inc_sudoku_io
#include <iostream>
#include <string>
#include "sudoku.h"

namespace sudoku {
	namespace io {
		extern std::ostream* log;

		inline void enable_logging (std::ostream& stream) { log = &stream; };
		inline void enable_logging () { log = &std::cout; };
		inline void disable_logging () { log = nullptr; };

		template <std::size_t n, typename char_t>
		void pretty_print (Puzzle<n> puzzle, std::basic_ostream<char_t>& stream);

		template <std::size_t n>
		void pretty_print (Puzzle<n> puzzle) { pretty_print(puzzle, std::cout); };

		template <size_t n, typename char_t>
		Puzzle<n> read_puzzle (std::basic_istream<char_t>& stream);

		// template <std::size_t n>
		// void write_puzzle (Puzzle<n> puzzle, std::ostream& stream, std::string col_sep, std::string row_sep);
		//
		// template <std::size_t n>
		// void write_puzzle (Puzzle<n> puzzle, std::ostream& stream) { write_puzzle(puzzle, stream, ",", "\n"); };
	}
}

#include "sudoku/impl/io.h"

#endif
