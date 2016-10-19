#include "gtest/gtest.h"
#include <sstream>
#include <array>
#include <algorithm>
#include <string>
#include "sudoku.h"
#include "sudoku/io.h"

using namespace std;
using namespace sudoku;

TEST(PrettyPrint, 2puzzle) {
	array<int, 16> vals = {
		4, 1, 3, 2,
		3, 2, 0, 1,
		2, 3, 1, 4,
		0, 4, 2, 3
	};

	string expected = "4 1 | 3 2\n3 2 |   1\n----+----\n2 3 | 1 4\n  4 | 2 3\n\n";
	//                 ----+----
	Puzzle<2> puz;
	ostringstream out;
	copy(begin(vals), end(vals), begin(puz.access()));
	io::pretty_print(puz);
	io::pretty_print(puz, out);
	EXPECT_EQ(out.str(), expected);
}
