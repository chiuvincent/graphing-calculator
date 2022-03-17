#ifndef COSINE_H
#define COSINE_H
#include "token.h"

class cosine: public token
{
public:
    cosine();
    cosine(string str);

    virtual void print();
    virtual char type();
};

#endif // COSINE_H
