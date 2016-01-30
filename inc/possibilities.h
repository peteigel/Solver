//
//  possibilities.h
//  solver2
//
//  Created by Pete Eigel on 8/21/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#ifndef __solver2__possibilities__
#define __solver2__possibilities__

class Possibilities {
    int data;
    int allPossible;
    short min;
    short max;
    
    static int powerOfTwo(short pow);
    
public:
    Possibilities(short max);
    Possibilities(short min, short max);
    
    bool isPossible (short val);
    void setPossible (short val);
    void setPossible (short val, bool possible);
    void setImpossible (short val);
    void setAll(bool possible);
    short numPossible ();
    short firstPossible();
};

#endif /* defined(__solver2__possibilities__) */
