#ifndef NUM_H
#define NUM_H
#include "token.h"

class num: public token
{
public:
    num();
    num(string str);

    virtual void print();
    virtual char type();

    double number();

private:
    double d;


};

#endif // NUM_H
