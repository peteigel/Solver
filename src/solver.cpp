//
//  solver.cpp
//  solver2
//
//  Created by Pete Eigel on 8/25/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "solver.h"

Solver::Solver(Puzzle *puzzle) {
    this->puzzle = puzzle;
}

int Solver::deduceValues(CellGroup* group) {
    int cellsISolved = 0;

    for (int index = 0; index < 9; index++) {
        short val = group->getCell(index)->getValue();

        if (val != 0) {
            for (int indexTwo = 0; indexTwo < 9; indexTwo++) {
                if (indexTwo != index) {
                    group->getCell(indexTwo)->setImpossible(val);
                }
            }
        }
    }

    for (int index = 0; index < 9; index++) {
        Cell* cell = group->getCell(index);

        if (cell->getValue() == 0 && cell->numPossible() == 1) {
            cell->setValue(cell->firstPossible());
            cellsSolved++;
            cellsISolved++;
        }
    }

    return cellsISolved;
}

int Solver::pass() {
    int cellsISolved = 0;
    passes++;

    for (int index = 0; index < 9; index++) {
        cellsISolved += deduceValues(puzzle->row(index));
        cellsISolved += deduceValues(puzzle->col(index));
        cellsISolved += deduceValues(puzzle->box(index));
    }

    lastLastResult = lastResult;
    lastResult = cellsISolved;

    solved = (cellsSolved + cellsGiven == 81);
    hung = (lastLastResult == 0 && lastResult == 0);

    return cellsISolved;
}

void Solver::solve() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (puzzle->cell(x, y)->getValue() != 0) {
                cellsGiven++;
            }
        }
    }

    while (!solved && !hung) {
        pass();
    }
}
