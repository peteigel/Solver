#include "gtest/gtest.h"
#include <sstream>
#include <array>
#include <algorithm>
#include <string>
#include "sudoku.h"
#include "sudoku/io.h"

using namespace std;
using namespace sudoku;

class sample_2puzzle : public ::testing::Test {
public:
	array<int, 16> vals = {
		4, 1, 3, 2,
		3, 2, 0, 1,
		2, 3, 1, 4,
		0, 4, 2, 3
	};

	Puzzle<2> puz;

	virtual void SetUp () {
		copy(begin(vals), end(vals), begin(puz.access()));
	}
};

TEST_F(sample_2puzzle, pretty_print) {
	string expected = "4 1 | 3 2\n3 2 |   1\n----+----\n2 3 | 1 4\n  4 | 2 3\n\n";
	//                 ----+----
	ostringstream out;

	io::pretty_print(puz);
	io::pretty_print(puz, out);
	EXPECT_EQ(out.str(), expected);
}

TEST_F(sample_2puzzle, read_spaces) {
	istringstream input ("4 1 3 2\n3 2 0 1\n2 3 1 4\n0 4 2 3");
	auto output = io::read_puzzle<2>(input);
	io::pretty_print(output);
	EXPECT_TRUE(equal(begin(output.access()), end(output.access()), begin(vals)));
}

TEST_F(sample_2puzzle, read_csv) {
	istringstream input ("4,1,3,2\n3,2,0,1\n2,3,1,4\n0,4,2,3");
	auto output = io::read_puzzle<2>(input);
	io::pretty_print(output);
	EXPECT_TRUE(equal(begin(output.access()), end(output.access()), begin(vals)));
}

TEST_F(sample_2puzzle, read_wide_csv) {
	auto input = basic_istringstream<wchar_t>(L"4,1,3,2\n3,2,0,1\n2,3,1,4\n0,4,2,3");
	auto output = io::read_puzzle<2>(input);
	io::pretty_print(output);
	EXPECT_TRUE(equal(begin(output.access()), end(output.access()), begin(vals)));
}
