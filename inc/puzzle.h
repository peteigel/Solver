#ifndef h_solver__puzzle
#define h_solver__puzzle

#include "cell.h"
#include "cellGroup.h"

class Puzzle {
    Cell cells [81];

public:

    Cell* cell(int x, int y);

    CellGroup cellGroup(int id);
    CellGroup row(int y);
    CellGroup col(int x);
    CellGroup box(int index);

    int degreesOfFreedom();

    static int cellIndexInSquare(int x, int y);
    static int squareIndexOfCell(int x, int y);
};

#endif
