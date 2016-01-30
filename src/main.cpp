#include <iostream>

#include "puzzleio.h"
#include "puzzle.h"
#include "solver.h"

int main(int argc, const char * argv[]) {
    using namespace std;

    short input[81]  = {
        8, 1, 0, 0, 3, 0, 9, 0, 0,
        3, 0, 5, 0, 0, 9, 0, 0, 0,
        0, 7, 6, 0, 4, 0, 8, 0, 0,
        0, 0, 0, 0, 5, 3, 0, 8, 4,
        6, 0, 8, 9, 0, 4, 7, 0, 5,
        4, 5, 0, 7, 1, 0, 0, 0, 0,
        0, 0, 1, 0, 6, 0, 4, 9, 0,
        0, 0, 0, 5, 0, 0, 3, 0, 1,
        0, 0, 3, 0, 9, 0, 0, 7, 8
    };

    PuzzleData puzzleData;
    Puzzle puzzle;
    Solver solver (&puzzle);

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

    cout << "\n\n";
}
