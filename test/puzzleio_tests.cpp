//
//  puzzleio_tests.cpp
//  solver2
//
//  Created by Pete Eigel on 9/24/15.
//  Copyright © 2015 Pete Eigel. All rights reserved.
//

#include "catch.hpp"
#include "puzzleio.h"

SCENARIO("We create a the wikipedia puzzle") {
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
    
    Puzzle wiki;
    
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            Cell* cell = wiki.cell(x, y);
            cell->setValue(samplePuzzle[y * 9 + x]);
        }
    }
    
    WHEN("We export it") {
        PuzzleData testPD;
        testPD.fromPuzzle(&wiki);
        testPD.exportRaw("wiki.txt");
    }
}