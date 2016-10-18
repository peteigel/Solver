#include "gtest/gtest.h"
#include "sudoku.h"
#include "sudoku/solver.h"

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

class multiple_2puzzle : public ::testing::Test {
public:
	Puzzle<2> puz;

	const array<int, 16> puzArr = {
		0, 3, 2, 0,
		0, 0, 0, 3,
		0, 0, 0, 0,
		0, 1, 0, 0
	};

	virtual void SetUp () {
		copy(begin(puzArr), end(puzArr), begin(puz.access()));
	};
};

class evil_3puzzle : public ::testing::Test {
public:
	Puzzle<3> puz;

	const array<int, 81> puzArr = {
		0, 0, 1, 0, 2, 6, 0, 9, 0,
		0, 8, 0, 0, 0, 0, 0, 0, 0,
		0, 6, 0, 0, 0, 4, 0, 0, 1,
		0, 0, 8, 5, 0, 0, 0, 0, 4,
		6, 3, 0, 0, 0, 0, 0, 5, 8,
		1, 0, 0, 0, 0, 8, 9, 0, 0,
		9, 0, 0, 3, 0, 0, 0, 6, 0,
		0, 0, 0, 0, 0, 0, 0, 2, 0,
		0, 7, 0, 6, 1, 0, 5, 0, 0
	};

	const array<int, 81> solutionArr = {
		3, 4 ,1 ,7, 2, 6, 8, 9, 5,
		5, 8, 7, 1, 3, 9, 6, 4, 2,
		2, 6, 9, 8, 5, 4, 3, 7, 1,
		7, 9, 8, 5, 6, 3, 2, 1, 4,
		6, 3, 4, 2, 9, 1, 7, 5, 8,
		1, 2, 5, 4, 7, 8, 9, 3, 6,
		9, 1, 2, 3, 8, 5, 4, 6, 7,
		8, 5, 6, 9, 4, 7, 1, 2, 3,
		4, 7, 3, 6, 1, 2, 5, 8, 9
	};

	virtual void SetUp () {
		copy(begin(puzArr), end(puzArr), begin(puz.access()));
	};
};

TEST_F(simple_2puzzle, verify_fixture) {
	EXPECT_EQ(puz.access(0, 0).value(), 0);
	EXPECT_EQ(puz.access(1, 3).value(), 1);
}

TEST_F(simple_2puzzle, try_solve) {
	EXPECT_EQ(solver::try_solve(puz), solver::success);
	EXPECT_TRUE(equal(begin(puz.access()), end(puz.access()), begin(solutionArr)));
}

TEST_F(hard_2puzzle, try_solve) {
	EXPECT_EQ(solver::try_solve(puz), solver::success);
	EXPECT_TRUE(equal(begin(puz.access()), end(puz.access()), begin(solutionArr)));
}

TEST_F(multiple_2puzzle, solve) {
	auto result = solver::solve(puz, true);
	EXPECT_EQ(get<1>(result), solver::success);
	EXPECT_GT(get<2>(result), 1);
}

TEST_F(evil_3puzzle, solve_exhaustive) {
	auto result = solver::solve(puz, true);
	auto solution = get<0>(result);
	EXPECT_EQ(get<2>(result), 1);
	EXPECT_EQ(get<1>(result), solver::success);
	EXPECT_TRUE(equal(begin(solution.access()), end(solution.access()), begin(solutionArr)));
}

TEST_F(evil_3puzzle, solve) {
	auto result = solver::solve(puz, true);
	auto solution = get<0>(result);
	EXPECT_EQ(get<2>(result), 1);
	EXPECT_EQ(get<1>(result), solver::success);
	EXPECT_TRUE(equal(begin(solution.access()), end(solution.access()), begin(solutionArr)));
}

TEST_F(evil_3puzzle, benchmark) {
	for (int i = 0; i < 1000; i++) {
		solver::solve(puz, false);
	}
}
