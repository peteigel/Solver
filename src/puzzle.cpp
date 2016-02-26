//
//  puzzle.cpp
//  solver2
//
//  Created by Pete Eigel on 8/23/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "puzzle.h"

Cell* Puzzle::cell(int x, int y) {
    return &cells[(y * 9) + x];
}

CellGroup Puzzle::row(int y) {
    CellGroup group;
    for (int x = 0; x < 9; x++) {
        group.setCell(x, cell(x, y));
    }

    return group;
}

CellGroup Puzzle::col(int x) {
    CellGroup group;
    for (int y = 0; y < 9; y++) {
        group.setCell(y, cell(x, y));
    }

    return group;
}

CellGroup Puzzle::box(int index) {
    int topLeftX = (index % 3) * 3;
    int topLeftY = (index / 3) * 3;
    CellGroup group;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            group.setCell(y * 3 + x, cell(x + topLeftX, y + topLeftY));
        }
    }

    return group;
}

int Puzzle::cellIndexInSquare(int x, int y) {
    return (y % 3) * 3 + (x % 3);
}

int Puzzle::squareIndexOfCell(int x, int y) {
    return (y / 3) * 3 + (x / 3);
}
