#include "sudoku.h"

using namespace std;
using namespace sudoku;

template <size_t _n>
Cell<Puzzle<_n>::_max_val>& Puzzle<_n>::access (const size_t row, const size_t col) {
	return cells[row * _max_val + col];
}

template <size_t _n>
std::array<Cell<Puzzle<_n>::_max_val>*, Puzzle<_n>::_max_val> Puzzle<_n>::row (const std::size_t r) {
	std::array<Cell<_max_val>*, _max_val> arr;

	for (size_t c = 0; c < _max_val; c++) {
		arr[c] = &(access(r, c));
	}

	return arr;
}

template <size_t _n>
std::array<Cell<Puzzle<_n>::_max_val>*, Puzzle<_n>::_max_val> Puzzle<_n>::col (const std::size_t c) {
	std::array<Cell<_max_val>*, _max_val> arr;

	for (size_t r = 0; r < _max_val; r++) {
		arr[c] = &(access(r, c));
	}

	return arr;
}

template <size_t _n>
std::array<Cell<Puzzle<_n>::_max_val>*, Puzzle<_n>::_max_val> Puzzle<_n>::box (const std::size_t b) {
	std::array<Cell<_max_val>*, _max_val> arr;

	const size_t bc = (b % _n) * _n;
	const size_t br = (b / _n) * _n;

	for (size_t r_offset = 0; r_offset < _n; r_offset++) {
		for (size_t c_offset = 0; c_offset < _n; c_offset++) {
			arr[c_offset + r_offset * _n] = &(access(br + r_offset, bc + c_offset));
		}
	}

	return arr;
}

namespace sudoku {
	template class Puzzle<2>;
	template class Puzzle<3>;
	template class Puzzle<4>;
}
