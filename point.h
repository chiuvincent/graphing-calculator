#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "constants.h"

using namespace std;

struct point{
    double x;
    double y;

    point screen_transform(double x1, double y1, double x2, double y2);
    point rectangular_transform(double x1, double y1, double x2, double y2);

    friend ostream& operator <<(ostream& outs, const point& stuff);

};

#endif // POINT_H
