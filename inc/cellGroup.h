#ifndef h_solver__cellGroup
#define h_solver__cellGroup

#include "cell.h"

class CellGroup {
    Cell* cells [9] = {};

public:
    void setCell(int index, Cell* cell);
    Cell* getCell(int index);

    bool isDetermined(int val);
};

#endif
