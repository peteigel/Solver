#include <iostream>

#include "puzzleio.h"
#include "puzzle.h"
#include "solver.h"

int main(int argc, const char * argv[]) {
    using namespace std;

    short input[81]  = {
        7, 8, 0, 0, 0, 3, 0, 0, 0,
        0, 0, 0, 1, 0, 8, 3, 2, 0,
        0, 0, 0, 0, 0, 0, 9, 7, 0,
        0, 0, 0, 3, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 2, 0, 0, 0,
        0, 7, 3, 0, 0, 0, 0, 0, 0,
        0, 9, 8, 6, 0, 5, 0, 0, 0,
        0, 0, 0, 9, 0, 0, 0, 3, 6
    };

    PuzzleData puzzleData;
    Puzzle puzzle;
    Solver solver (puzzle);
    PuzzleData numPossible;

    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            puzzleData.values[x][y] = input[y * 9 + x];
        }
    }

    cout << "Input Puzzle\n";
    puzzleData.prettyPrint();

    cout << "\n\nSolution\n";
    puzzleData.toPuzzle(&puzzle);
    solver.solve();
    puzzleData.fromPuzzle(&puzzle);
    puzzleData.prettyPrint();

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            numPossible.values[col][row] = puzzle.row(row).getCell(col)->numPossible();
        }
    }

    cout << "\n\nValues Possible\n";
    numPossible.prettyPrint();

    cout << "\n\n";
}
