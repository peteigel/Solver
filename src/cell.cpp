#include "sudoku.h"
#include <algorithm>
#include <stdexcept>

using namespace std;
using namespace sudoku;

template <size_t max_val>
Cell<max_val>::Cell () {
	data.fill(true);
}

template <size_t max_val>
bool& Cell<max_val>::access (const int value) {
	return data[value + 1];
}

template <size_t max_val>
const bool& Cell<max_val>::access (const int value) const {
	return data[value + 1];
}

template <size_t max_val>
int Cell<max_val>::num_possible () const {
	return count(begin(data), end(data), true);
}

template <size_t max_val>
int Cell<max_val>::value () const {
	if (num_possible() != 1) {
		return 0;
	} else {
		for (int val = 1; val <= max_val; val++) {
			if (access(val)) { return val; }
		}

		throw logic_error("No Possible Values");
	}
}

template <size_t max_val>
void Cell<max_val>::set_value (const int value) {
	data.fill(false);
	access(value) = true;
}

namespace sudoku {
	template class Cell<4>;
	template class Cell<9>;
	template class Cell<16>;
}
