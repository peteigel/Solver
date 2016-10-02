#include <iostream>
#include "puzzle.h"

using namespace std;

template <size_t n>
void Puzzle<n>::print_max_val () {
	cout << max_val << endl;
}

template class Puzzle<3>;
