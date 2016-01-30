//
//  cell.h
//  solver2
//
//  Created by Pete Eigel on 8/12/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#ifndef __solver2__cell__
#define __solver2__cell__

#include "possibilities.h"

class Cell: public Possibilities{
    short value;
    void init();
    
public:
    Cell ();
    Cell (short val);
    
    short getValue ();
    void setValue (short val);
    short calculateValue();
};

#endif /* defined(__solver2__cell__) */
