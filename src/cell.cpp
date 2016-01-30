//
//  cell.cpp
//  solver2
//
//  Created by Pete Eigel on 8/12/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "cell.h"

void Cell::init() {
    value = 0;
    setAll(true);
}

Cell::Cell () : Possibilities(1,9) {
    init();
}

Cell::Cell (short val) : Possibilities(1,9) {
    init();
    setValue(val);
}

short Cell::getValue() {
    return value;
}

short Cell::calculateValue() {
    int n = numPossible();
    
    if (n > 1) {
        value = 0;
    } else if (n == 1) {
        value = firstPossible();
    } else {
        value = -1;
    }
    
    return value;
}

void Cell::setValue(short val) {
    if (val == 0) {
        init();
    } else {
        value = val;
        setAll(false);
        setPossible(val);
    }
}