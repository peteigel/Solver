//
//  puzzle.cpp
//  solver2
//
//  Created by Pete Eigel on 8/23/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "puzzle.h"

Cell* Puzzle::cell (int x, int y) {
    return &cells[(y * 9) + x];
}

CellGroup Puzzle::row (int y) {
    CellGroup group;
    for (int x = 0; x < 9; x++) {
        group.setCell(x, cell(x, y));
    }

    return group;
}

CellGroup Puzzle::col (int x) {
    CellGroup group;
    for (int y = 0; y < 9; y++) {
        group.setCell(y, cell(x, y));
    }

    return group;
}

CellGroup Puzzle::box (int index) {
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

CellGroup Puzzle::cellGroup (int id) {
    if (id % 3 == 0) {
        return row(id / 3);
    } else if (id % 3 == 1) {
        return col(id / 3);
    } else {
        return box(id / 3);
    }
}

int Puzzle::degreesOfFreedom () {
    int dof = 0;

    for (int cellIndex = 0; cellIndex < 81; cellIndex++) {
        dof += cells[cellIndex].numPossible() - 1;
    }

    return dof;
}

int Puzzle::cellIndexInSquare(int x, int y) {
    return (y % 3) * 3 + (x % 3);
}

int Puzzle::squareIndexOfCell(int x, int y) {
    return (y / 3) * 3 + (x / 3);
}
