#ifndef OPE_H
#define OPE_H
#include "token.h"


class ope: public token
{
public:
    ope();
    ope(string str);

    virtual void print();
    virtual char type();

    string operate();
    int precedence();

private:
    int pr;
    string op;
};

#endif // OPE_H
