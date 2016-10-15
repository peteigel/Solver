#include "gtest/gtest.h"
#include "sudoku.h"
#include <stdexcept>

using namespace std;
using namespace sudoku;

TEST(puzzle, row_and_col) {
	auto test_puz = Puzzle<> {};
	for (unsigned int r = 0; r < 9; r++) {
		for (unsigned int c = 0; c < 9; c++) {
			EXPECT_EQ(&(test_puz.access(r, c)), test_puz.row(r)[c]);
			EXPECT_EQ(&(test_puz.access(r, c)), test_puz.col(c)[r]);
		}
	}
}

TEST(puzzle, square) {
	auto test_puz = Puzzle<> {};
	EXPECT_EQ(&(test_puz.access(0, 0)), test_puz.box(0)[0]);
	EXPECT_EQ(&(test_puz.access(8, 8)), test_puz.box(8)[8]);
	EXPECT_EQ(&(test_puz.access(0, 8)), test_puz.box(2)[2]);
}

TEST(cell, init_and_set_value) {
	auto test_cell = Cell<9> {};

	for (int val = 1; val <= 9; val++) {
		EXPECT_TRUE(test_cell.access(val));
	}

	EXPECT_EQ(test_cell.num_possible(), 9);

	test_cell.set_value(3);

	for (int val = 1; val <= 9; val++) {
		EXPECT_EQ(test_cell.access(val), val == 3);
	}

	EXPECT_EQ(test_cell.num_possible(), 1);
	EXPECT_EQ(test_cell.value(), 3);
}

TEST(cell, determine_value_from_elimination) {
	auto test_cell = Cell<9> {};

	for (int val = 1; val <= 9; val++) {
		test_cell.access(val) = (val == 8);
	}

	EXPECT_EQ(test_cell.num_possible(), 1);
	EXPECT_EQ(test_cell.value(), 8);
}

TEST(cell, throws_when_no_possible_value) {
	auto test_cell = Cell<9> {};

	for (int val = 1; val <= 9; val++) {
		test_cell.access(val) = false;
	}

	EXPECT_THROW(test_cell.value(), invalid_puzzle);
}

TEST(cell, operator_overloads) {
	auto test_cell = Cell<9> {};
	EXPECT_TRUE(test_cell == 0);
	test_cell = 9;
	EXPECT_TRUE(test_cell == 9);
	EXPECT_FALSE(test_cell[1]);
	EXPECT_TRUE(test_cell[9]);
}
