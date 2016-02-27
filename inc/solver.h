#ifndef h_solver__solver__
#define h_solver__solver__

#include "puzzle.h"
#include "cellGroup.h"
#include "cell.h"

class Solver {
    Puzzle puzzle;
    bool solved      = false;
    bool hung        = false;

    int  passes      = 0;
    int  cellsGiven  = 0;
    int  cellsSolved = 0;

    int lastResult      = -1;
    int lastLastResult  = -1;

public:
    Solver (Puzzle puzzle);

    Puzzle getPuzzle();
    bool isSolved();
    bool isHung();

    void solve();
    int pass();

    int deduceValues(CellGroup group);
    int induceValues(CellGroup group);
};

#endif
