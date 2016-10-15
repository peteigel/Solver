#include "gtest/gtest.h"
#include "sudoku.h"
#include "solver.h"

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;
using namespace sudoku;

template <size_t n>
void printPuzzle (Puzzle<n> puz) {
	for (size_t row = 0; row < puz.max_val(); row++) {
		for (size_t col = 0; col < puz.max_val(); col++) {
			cout << puz.access(row, col).value();
		}
		cout << '\n';
	}
};

class simple_2puzzle : public ::testing::Test {

public:
	Puzzle<2> puz;

	const array<int, 16> puzArr = {
		0 ,0, 3, 0,
		3, 0, 0, 1,
		2, 0, 0, 4,
		0, 4, 0, 0
	};

	const array<int, 16> solutionArr = {
		4, 1, 3, 2,
		3, 2, 4, 1,
		2, 3, 1, 4,
		1, 4, 2, 3
	};

	virtual void SetUp () {
		copy(begin(puzArr), end(puzArr), begin(puz.access()));
	};
};

class hard_2puzzle : public ::testing::Test {
public:
	Puzzle<2> puz;

	const array<int, 16> puzArr = {
		0, 3, 2, 0,
		0, 0, 0, 3,
		4, 0, 0, 0,
		0, 1, 0, 0
	};

	const array<int, 16> solutionArr = {
		1, 3, 2, 4,
		2, 4, 1, 3,
		4, 2, 3, 1,
		3, 1, 4, 2
	};

	virtual void SetUp () {
		copy(begin(puzArr), end(puzArr), begin(puz.access()));
	};
};

TEST_F(simple_2puzzle, verify_fixture) {
	EXPECT_EQ(puz.access(0, 0).value(), 0);
	EXPECT_EQ(puz.access(1, 3).value(), 1);
}

TEST_F(simple_2puzzle, solve) {
	EXPECT_EQ(solver::try_solve(puz), solver::success);
	EXPECT_TRUE(equal(begin(puz.access()), end(puz.access()), begin(solutionArr)));
}

TEST_F(hard_2puzzle, solve) {
	EXPECT_EQ(solver::try_solve(puz), solver::success);
	EXPECT_TRUE(equal(begin(puz.access()), end(puz.access()), begin(solutionArr)));
}
