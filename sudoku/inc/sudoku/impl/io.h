#include <array>
#include <algorithm>
#include <string>
#include <iostream>
#include <string>

namespace sudoku {
	namespace io {
		template <size_t n, typename char_t>
		void pretty_print (Puzzle<n> puzzle, std::basic_ostream<char_t>& stream) {
			stream << std::hex;
			for (size_t row = 0; row < puzzle.max_val(); row++) {
				for (size_t col = 0; col < puzzle.max_val(); col++) {
					try {
						auto val = puzzle.access(row, col).value();
						if (!val) {
							stream << " ";
						} else {
							stream << val;
						}
					} catch (invalid_puzzle& e) {
						stream << "X";
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
							if (n > 2) {
								stream << "+-";
							} else {
								stream <<  "+";
							}
						}
					}
					stream << '\n';
				}
			}

			stream << std::dec;
		};

		template <size_t n, typename char_t>
		Puzzle<n> read_puzzle (std::basic_istream<char_t>& stream) {
			auto next_int = [&]() -> int {
				const std::array<char_t, 10> numerals = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
				std::basic_string<char_t> temp;

				while (!stream.fail()) {
					char_t next_char = stream.peek();

					if (std::count(begin(numerals), end(numerals), next_char)) {
						temp += stream.get();
					} else {
						if (!temp.empty()) {
							return std::stoi(temp);
						}

						stream.get();
					}
				}

				throw std::out_of_range("Reached end of file before filling puzzle");
			};

			Puzzle<n> puzzle;
			for (int i = 0; i < puzzle.num_cells(); i++) {
				int v = next_int();
				puzzle.access()[i] = v;
			}

			return puzzle;
		};

		template <std::size_t n, typename char_t>
		void write_puzzle (Puzzle<n> puzzle, std::basic_ostream<char_t>& stream, std::string col_sep, std::string row_sep) {
			for (int row = 0; row < puzzle.max_val(); row++) {
				for (int col = 0; col < puzzle.max_val(); col++) {
					stream << puzzle.access(row, col).value();
					if (col < puzzle.max_val() - 1) {
						stream << col_sep;
					}
				}

				if (row < puzzle.max_val() - 1) {
					stream << row_sep;
				}
			}
		};
	}
}
