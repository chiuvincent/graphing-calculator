#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                      //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar

};

string mouse_pos_string(sf::RenderWindow& window);

#endif // GAME_H
