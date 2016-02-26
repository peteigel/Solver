//
//  puzzle.h
//  solver2
//
//  Created by Pete Eigel on 8/23/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#ifndef __solver2__puzzle__
#define __solver2__puzzle__

#include "cell.h"
#include "cellGroup.h"

class Puzzle {
    Cell cells [81];

public:

    Cell* cell(int x, int y);

    // CellGroup* cellGroup(int index);
    CellGroup row(int y);
    CellGroup col(int x);
    CellGroup box(int index);

    static int cellIndexInSquare(int x, int y);
    static int squareIndexOfCell(int x, int y);
};

#endif /* defined(__solver2__puzzle__) */
