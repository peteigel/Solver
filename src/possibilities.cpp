//
//  possibilities.cpp
//  solver2
//
//  Created by Pete Eigel on 8/21/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "possibilities.h"

Possibilities::Possibilities(short min, short max) {
    this->min = min;
    this->max = max;
    data = 0;
    allPossible = powerOfTwo(max-min) - 1;
}

Possibilities::Possibilities(short max) {
    this->max = max;
    min = 0;
    data = 0;
    allPossible = powerOfTwo(max);
}

int Possibilities::powerOfTwo(short pow) {
    int result = 1;
    while (pow >= 0) {
        result *= 2;
        pow--;
    }
    return result;
}

void Possibilities::setPossible (short val, bool possible) {
    if (possible) {
        setPossible(val);
    } else {
        setImpossible(val);
    }
}

void Possibilities::setPossible (short val) {
    int filter = 0x1 << (val - min);
    data = data | filter;
}

void Possibilities::setImpossible (short val) {
    int filter = allPossible - (0x1 << (val - min));
    data = data & filter;
}

void Possibilities::setAll(bool possible) {
    if (possible) {
        data = allPossible;
    } else {
        data = 0x0;
    }
}

bool Possibilities::isPossible(short val) {
    int filter = data >> (val - min);
    filter = filter & 0x1;
    return filter == 1;
}

short Possibilities::numPossible() {
    short count = 0;
    
    for (short i = 1; i <=9; i++) {
        if (isPossible(i)) {
            count++;
        }
    }
    
    return count;
}

short Possibilities::firstPossible() {
    for (short val = min; val <= max; val++) {
        if (isPossible(val)) {
            return val;
        }
    }
    
    return min - 1;
}