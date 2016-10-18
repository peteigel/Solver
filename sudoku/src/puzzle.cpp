#include "sudoku.h"

using namespace std;
using namespace sudoku;

template <size_t _n>
array<Cell<Puzzle<_n>::_max_val>, Puzzle<_n>::_n_cells>& Puzzle<_n>::access () {
	return cells;
}

template <size_t _n>
const array<Cell<Puzzle<_n>::_max_val>, Puzzle<_n>::_n_cells>&  Puzzle<_n>::access () const {
	return cells;
}

template <size_t _n>
const Cell<Puzzle<_n>::_max_val>& Puzzle<_n>::access (const size_t row, const size_t col) const {
	return cells[row * _max_val + col];
}

template <size_t _n>
Cell<Puzzle<_n>::_max_val>& Puzzle<_n>::access (const size_t row, const size_t col) {
	return cells[row * _max_val + col];
}

template <size_t _n>
array<Cell<Puzzle<_n>::_max_val>*, Puzzle<_n>::_max_val> Puzzle<_n>::row (const size_t r) {
	array<Cell<_max_val>*, _max_val> arr;

	for (size_t c = 0; c < _max_val; c++) {
		arr[c] = &(access(r, c));
	}

	return arr;
}

template <size_t _n>
array<Cell<Puzzle<_n>::_max_val>*, Puzzle<_n>::_max_val> Puzzle<_n>::col (const size_t c) {
	array<Cell<_max_val>*, _max_val> arr;

	for (size_t r = 0; r < _max_val; r++) {
		arr[r] = &(access(r, c));
	}

	return arr;
}

template <size_t _n>
array<Cell<Puzzle<_n>::_max_val>*, Puzzle<_n>::_max_val> Puzzle<_n>::box (const size_t b) {
	array<Cell<_max_val>*, _max_val> arr;

	const size_t bc = (b % _n) * _n;
	const size_t br = (b / _n) * _n;

	for (size_t r_offset = 0; r_offset < _n; r_offset++) {
		for (size_t c_offset = 0; c_offset < _n; c_offset++) {
			arr[c_offset + r_offset * _n] = &(access(br + r_offset, bc + c_offset));
		}
	}

	return arr;
}

template <size_t _n>
array<Cell<Puzzle<_n>::_max_val>*, Puzzle<_n>::_max_val> Puzzle<_n>::group (const std::size_t g) {
	switch (g / _max_val) {
		case 0: return row(g % _max_val);
		case 1: return col(g % _max_val);
		case 2: return box(g % _max_val);
	};

	throw new std::domain_error("Invalid group ID");
}

namespace sudoku {
	template class Puzzle<2>;
	template class Puzzle<3>;
	template class Puzzle<4>;
}
