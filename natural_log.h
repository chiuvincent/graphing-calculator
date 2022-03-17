#ifndef NATURAL_LOG_H
#define NATURAL_LOG_H
#include "token.h"

class natural_log: public token
{
public:
    natural_log();
    natural_log(string str);

    virtual void print();
    virtual char type();
};

#endif // NATURAL_LOG_H
