#include "sudoku.h"
#include <iostream>

using namespace std;
using namespace sudoku;

int main () {
	auto myPuz = Puzzle<2> {};
	myPuz.access(0, 3).set_value(1);
	auto firstRow = myPuz.row(0);

	for (auto c : firstRow) {
		cout << c->value() << " ";
	}

	cout << endl;
}
