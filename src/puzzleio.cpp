//
//  puzzleio.cpp
//  solver2
//
//  Created by Pete Eigel on 9/15/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "puzzleio.h"

short PuzzleData::operator()(int x, int y) {
    return values[x][y];
}

void PuzzleData::toPuzzle(Puzzle *puzzle) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            puzzle->cell(x, y)->setValue(values[x][y]);
        }
    }
}

void PuzzleData::fromPuzzle(Puzzle *puzzle) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            values[x][y] = puzzle->cell(x, y)->getValue();
        }
    }
}

template <class OStream>
void PuzzleData::prettyPrint(OStream* stream) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            int val = values[x][y];
            
            string sVal;
            
            if (val == 0) {
                sVal = " ";
            } else {
                sVal = to_string(val);
            }
            
            *stream << sVal;
            
            if (x == 2 || x == 5) {
                *stream << " | ";
            } else if(x < 8) {
                *stream <<  " ";
            }
        }
        
        if (y == 2 || y == 5) {
            *stream << "\n------+-------+------\n";
        } else if(y < 8) {
            *stream << "\n";
        }
    }
}

void PuzzleData::prettyPrint() {
    prettyPrint(&cout);
}

template <class OStream>
void PuzzleData::print(OStream* stream, string separator) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            int val = values[x][y];
            
            string sVal = to_string(val);
            
            *stream << sVal;
            *stream << separator;
            
        }
        
        *stream << "\n";
    }
}

void PuzzleData::print(string separator) {
    print(&cout, separator);
}

void PuzzleData::print() {
    print("");
}

void PuzzleData::exportRaw(string filename) {
    using namespace std;
    
    fstream file;
    file.open(filename.c_str(), fstream::in | fstream::out | fstream::trunc);
    
    print(&file, "");
}