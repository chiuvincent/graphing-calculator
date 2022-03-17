#ifndef SINE_H
#define SINE_H
#include "token.h"

class sine: public token
{
public:
    sine();
    sine(string str);

    virtual void print();
    virtual char type();
};

#endif // SINE_H
