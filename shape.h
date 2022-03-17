#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <SFML/Graphics.hpp>

#include <iostream>

class shape
{
public:
    shape();
    shape(double xpos, double ypos);
    void draw(sf::RenderWindow& window);

protected:
    float shape_size;
    sf::Vector2f pos;

    sf::CircleShape c;
};

#endif // SHAPE_H
