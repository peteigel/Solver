//
//  solver.h
//  solver2
//
//  Created by Pete Eigel on 8/25/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#ifndef __solver2__solver__
#define __solver2__solver__

#include "puzzle.h"
#include "cellGroup.h"
#include "cell.h"

class Solver {
    Puzzle* puzzle   = nullptr;
    bool solved      = false;
    bool hung        = false;
    
    int  passes      = 0;
    int  cellsGiven  = 0;
    int  cellsSolved = 0;
    
    int lastResult      = -1;
    int lastLastResult  = -1;
    
public:
    Solver (Puzzle* puzzle);
    void solve();
    int pass();
    
    int deduceValues(CellGroup* group);
    int induceValues(CellGroup* group);
};

#endif /* defined(__solver2__solver__) */
