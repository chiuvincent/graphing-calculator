#include "shape.h"
#include "constants.h"
#include <iostream>
using namespace std;
shape::shape(){
    shape_size = 1;
    pos = sf::Vector2f(0,0);
    c = sf::CircleShape(shape_size);
    c.setPosition(pos);
}

shape::shape(double xpos, double ypos){
    shape_size = 1;
    pos = sf::Vector2f(xpos-shape_size,ypos-shape_size);
    c = sf::CircleShape(shape_size);
    c.setPosition(pos);
//    c.setFillColor(sf::Color::Red);
}

void shape::draw(sf::RenderWindow& window){
    window.draw(c);
}
