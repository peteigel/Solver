#ifndef h_solver__cell
#define h_solver__cell

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

#endif
