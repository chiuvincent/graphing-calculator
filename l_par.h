#ifndef L_PAR_H
#define L_PAR_H
#include "token.h"

class L_par: public token
{
public:
    L_par();
    L_par(string str);

    virtual void print();
    virtual char type();
};

#endif // L_PAR_H
