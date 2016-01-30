//
//  puzzle.cpp
//  solver2
//
//  Created by Pete Eigel on 8/23/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "puzzle.h"

Puzzle::Puzzle() {
    for (int x = 0; x < 9; x ++) {
        for (int y = 0; y < 9; y++) {
            Cell* cellPtr = cell(x, y);
            
            row(y)->setCell(x, cellPtr);
            col(x)->setCell(y, cellPtr);
            
            box(squareIndexOfCell(x, y))->setCell(cellIndexInSquare(x, y), cellPtr);
        }
    }
}

template <class Archive>
void Puzzle::serialize(Archive& archive , const unsigned int version) {
    archive & cells;
}

Cell* Puzzle::cell(int x, int y) {
    return &cells[(y * 9) + x];
}

CellGroup* Puzzle::row(int y) {
    return &cellGroups[y * 3];
}

CellGroup* Puzzle::col(int x) {
    return &cellGroups[x * 3 + 1];
}

CellGroup* Puzzle::box(int index) {
    return &cellGroups[index * 3 + 2];
}

int Puzzle::cellIndexInSquare(int x, int y) {
    return (y % 3) * 3 + (x % 3);
}

int Puzzle::squareIndexOfCell(int x, int y) {
    return (y / 3) * 3 + (x / 3);
}