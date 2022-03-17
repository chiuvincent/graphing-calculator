#ifndef R_PAR_H
#define R_PAR_H
#include "token.h"

class R_par: public token
{
public:
    R_par();
    R_par(string str);

    virtual void print();
    virtual char type();
};

#endif // R_PAR_H
