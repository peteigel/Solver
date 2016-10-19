#include "sudoku/io.h"
using namespace std;
using namespace sudoku;

ostream* io::log = nullptr;

template <size_t n>
void io::pretty_print (Puzzle<n> puzzle, ostream& stream) {
	for (size_t row = 0; row < puzzle.max_val(); row++) {
		for (size_t col = 0; col < puzzle.max_val(); col++) {
			auto val = puzzle.access(row, col).value();
			if (!val) {
				stream << " ";
			} else {
				stream << std::hex << val;
			}

			if (col == puzzle.max_val() - 1) {
				stream << '\n';
			} else if (col % n == n - 1) {
				stream << " | ";
			} else {
				stream << " ";
			}
		}

		if (row == puzzle.max_val() - 1) {
			stream << '\n';
		} else if (row % n == n - 1) {
			for (size_t i = 0; i < n; i++) {
				for (size_t j = 0; j < n; j++) {
					stream << "--";
				}

				if (i < n - 1) {
					stream << '+';
				}
			}
			stream << '\n';
		}
	}
}

namespace sudoku {
	namespace io {
		template void pretty_print<2> (Puzzle<2> puzzle, ostream& stream);
		template void pretty_print<3> (Puzzle<3> puzzle, ostream& stream);
		template void pretty_print<4> (Puzzle<4> puzzle, ostream& stream);
	}
}
