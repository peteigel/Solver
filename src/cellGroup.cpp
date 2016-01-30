//
//  cellGroup.cpp
//  solver2
//
//  Created by Pete Eigel on 8/23/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "cellGroup.h"


void CellGroup::setCell(int index, Cell* cell) {
    cells[index] = cell;
}

Cell* CellGroup::getCell(int index) {
    return cells[index];
}

bool CellGroup::isDetermined(int val) {
    for (int i = 0; i < 9; i++) {
        if (getCell(i)->getValue() == val) {
            return true;
        }
    }
    
    return false;
}