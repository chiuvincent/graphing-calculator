#ifndef EVALUATOR_H
#define EVALUATOR_H
#include <string>
#include <cstring>
#include <cmath>
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
#include "rpn.h"
#include "shunting_yard.h"
#include "point.h"

class evaluator
{
public:
    evaluator();
    evaluator(string str);

    double calculate(); //tokenizer included
    point* graph(double min, double max, int dots, point& minmax);

private:
    double calculate(double x);
    string s;

};

#endif // EVALUATOR_H
