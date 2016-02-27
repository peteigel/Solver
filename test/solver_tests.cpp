//
//  solver_tests.cpp
//  solver2
//
//  Created by Pete Eigel on 8/25/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include <iostream>

#include "catch.hpp"
#include "solver.h"
#include "puzzleio.h"


// From: https://en.wikipedia.org/wiki/Sudoku#/media/File:Sudoku-by-L2G-20050714.svg

short samplePuzzle[81] = {
    5, 3, 0, 0, 7, 0, 0, 0, 0,
    6, 0, 0, 1, 9, 5, 0, 0, 0,
    0, 9, 8, 0, 0, 0, 0, 6, 0,
    8, 0, 0, 0, 6, 0, 0, 0, 3,
    4, 0, 0, 8, 0, 3, 0, 0, 1,
    7, 0, 0, 0, 2, 0, 0, 0, 6,
    0, 6, 0, 0, 0, 0, 2, 8, 0,
    0, 0, 0, 4, 1, 9, 0, 0, 5,
    0, 0, 0, 0, 8, 0, 0, 7, 9
};

short sampleSolution[81] = {
    5, 3, 4, 6 ,7, 8, 9, 1, 2,
    6, 7, 2, 1, 9, 5, 3, 4, 8,
    1, 9, 8, 3, 4, 2, 5, 6, 7,
    8, 5, 9, 7, 6, 1, 4, 2, 3,
    4, 2, 6, 8, 5, 3, 7, 9, 1,
    7, 1, 3, 9, 2, 4, 8, 5, 6,
    9, 6, 1, 5, 3, 7, 2, 8, 4,
    2, 8, 7, 4, 1, 9, 6, 3, 5,
    3, 4, 5, 2, 8, 6, 1, 7, 9
};

SCENARIO("A new solver is made with the Wikipedia puzzle") {
    Puzzle wiki;

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            Cell* cell = wiki.cell(x, y);
            cell->setValue(samplePuzzle[y * 9 + x]);
        }
    }

    Solver testSolver {wiki};

    WHEN("We deduceValues for the first column") {
        int numSolved = testSolver.deduceValues(wiki.col(0));

        THEN("Zero cells are solved") {
            REQUIRE(numSolved == 0);
        }

        THEN("7 is impossible in cell 0,7") {
            REQUIRE(! wiki.cell(0, 7)->isPossible(7));
        }

        THEN("8 is impossible in cell 0,2") {
             REQUIRE(! wiki.cell(0, 2)->isPossible(8));
        }
    }

    WHEN("We deduceValues for all lists that contain 7,7") {
        int rowSolved = testSolver.deduceValues(wiki.row(7));
        int colSolved = testSolver.deduceValues(wiki.col(7));
        int boxSolved = testSolver.deduceValues(wiki.box(wiki.squareIndexOfCell(7, 7)));

        THEN("At least one cell was solved") {
            REQUIRE(rowSolved + colSolved + boxSolved >= 1);
        }

        THEN("The value of 7,7 is 3") {
            REQUIRE(wiki.cell(7, 7)->getValue() == 3);
        }
    }

    WHEN("We try solve a puzzle just for fun") {
        testSolver.solve();

        THEN("The solution magically appears") {
            for (int x = 0; x < 9; x++) {
                for (int y = 0; y < 9; y++) {
                    REQUIRE(testSolver.getPuzzle().cell(x, y)->getValue() == sampleSolution[y * 9 + x]);
                }
            }
        }
    }
}
