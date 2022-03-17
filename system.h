#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "random.h"
#include "constants.h"
#include "evaluator.h"
#include "point.h"
#include "queue.h"
#include "shape.h"

using namespace std;
class System
{
public:
    System();
    System(string x);
    void Step(int command);
    void Draw(sf::RenderWindow& window);

    void reset_x(double new_min, double new_max);
    void reset_y(double new_min, double new_max);
    void reset_function(string x);

    string get_equation();

private:
    string equation;

    point* graph;
    shape* f;
    point minmax;
    int dots;
    evaluator e;

    double x1;
    double y1;
    double x2;
    double y2;

    point x_origin;
    point y_origin;
    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;

    double x_incr;
    double y_incr;
};

#endif // SYSTEM_H
