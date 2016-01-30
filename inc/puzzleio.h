//
//  puzzleio.h
//  solver2
//
//  Created by Pete Eigel on 9/15/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#ifndef __solver2__puzzleio__
#define __solver2__puzzleio__

#include <string>
#include <iostream>
#include <fstream>

#include "puzzle.h"

using namespace std;

class PuzzleData {
public:
    short values[9][9] = {};
    
    short operator () (int x, int y);
    
    void toPuzzle(Puzzle* puzzle);
    void fromPuzzle(Puzzle* puzzle);
    void exportRaw(string filename);
    void importRaw(string filename);
    
    template <class OStream>
    void prettyPrint (OStream* stream);
    void prettyPrint ();
    
    template <class OStream>
    void print (OStream* stream, string separator);
    void print (string separator);
    void print ();
};

#endif /* defined(__solver2__puzzleio__) */
