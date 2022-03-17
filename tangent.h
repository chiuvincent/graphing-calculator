#ifndef TANGENT_H
#define TANGENT_H
#include "token.h"

class tangent: public token
{
public:
    tangent();
    tangent(string str);

    virtual void print();
    virtual char type();
};

#endif // TANGENT_H
