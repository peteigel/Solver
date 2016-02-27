//
//  solver.cpp
//  solver2
//
//  Created by Pete Eigel on 8/25/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "solver.h"

Solver::Solver(Puzzle puzzle) {
    this->puzzle = puzzle;
}

Puzzle Solver::getPuzzle () {
    return puzzle;
}

bool Solver::isSolved () {
    return solved;
}

int Solver::induceValues(CellGroup group) {
    int cellsISolved = 0;
    int numPossible;
    Cell* lastPossible;

    for (short value = 1; value <= 9; value++) {
        numPossible = 0;
        lastPossible = nullptr;

        for (int index = 0; index < 9; index++) {
            Cell* currentCell = group.getCell(index);
            if (currentCell->isPossible(value)) {
                numPossible++;
                lastPossible = currentCell;
            }
        }

        if (numPossible == 1 && lastPossible->getValue() == 0) {
            lastPossible->setValue(value);
            cellsISolved++;
        }
    }

    return cellsISolved;
}

int Solver::deduceValues(CellGroup group) {
    int cellsISolved = 0;

    for (int index = 0; index < 9; index++) {
        short val = group.getCell(index)->getValue();

        if (val != 0) {
            for (int indexTwo = 0; indexTwo < 9; indexTwo++) {
                if (indexTwo != index) {
                    group.getCell(indexTwo)->setImpossible(val);
                }
            }
        }
    }

    for (int index = 0; index < 9; index++) {
        Cell* cell = group.getCell(index);

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
        cellsISolved += deduceValues(puzzle.row(index));
        cellsISolved += deduceValues(puzzle.col(index));
        cellsISolved += deduceValues(puzzle.box(index));
        cellsISolved += induceValues(puzzle.row(index));
        cellsISolved += induceValues(puzzle.col(index));
        cellsISolved += induceValues(puzzle.box(index));
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
            if (puzzle.cell(x, y)->getValue() != 0) {
                cellsGiven++;
            }
        }
    }

    while (!solved && !hung) {
        pass();
    }
}
