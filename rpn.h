#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <cmath>
#include "token.h"
#include "num.h"
#include "ope.h"
#include "sine.h"
#include "cosine.h"
#include "tangent.h"
#include "natural_log.h"
#include "queue.h"
#include "stack.h"

using namespace std;

class RPN
{
public:
    RPN();
    RPN(queue<token*> in);

    double compute();

private:
    queue<token*> input;
};

#endif // RPN_H
