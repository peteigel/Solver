#ifndef h_solver__possibilities
#define h_solver__possibilities

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

#endif
