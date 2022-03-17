#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include <iostream>
#include "token.h"
#include "num.h"
#include "ope.h"
#include "l_par.h"
#include "r_par.h"
#include "sine.h"
#include "cosine.h"
#include "tangent.h"
#include "natural_log.h"
#include "queue.h"
#include "stack.h"

using namespace std;

class shunting_yard
{
public:
    shunting_yard();
    shunting_yard(queue<token*> infix);

    queue<token*> postfix();

private:
    queue<token*> input;
    queue<token*> rpn;
};

#endif // SHUNTING_YARD_H
