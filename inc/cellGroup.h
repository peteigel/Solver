//
//  cellGroup.h
//  solver2
//
//  Created by Pete Eigel on 8/23/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#ifndef __solver2__cellGroup__
#define __solver2__cellGroup__

#include "cell.h"

class CellGroup {
    Cell* cells [9] = {};
    
public:
    void setCell(int index, Cell* cell);
    Cell* getCell(int index);
    
    bool isDetermined(int val);
};

#endif /* defined(__solver2__cellGroup__) */
