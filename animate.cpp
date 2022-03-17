#include "animate.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <cstring>
#include "system.h"

using namespace std;



animate::animate():sidebar(WORK_PANEL, SIDE_BAR)
{
    cout<<"animate CTOR: TOP"<<endl;

    string x;
    cout<<"ENTER FUNCTION:\t";
    getline(cin,x);
    system = System(x);
    sidebar[SB_KEY_PRESSED] = "FUNCTION";
    sidebar[FUNCTION_CHOSEN] = x;
    sidebar.load("sidebar.txt");
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Vincent Chiu");
    window.setFramerateLimit(60);


    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will

    mouseIn = true;

//    mousePoint = sf::CircleShape();
//    mousePoint.setRadius(5.0);
//    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Game CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

//    myTextLabel = sf::Text("Vincent's Bouncing Shapes", font);
//    myTextLabel.setCharacterSize(12);
//    myTextLabel.setStyle(sf::Text::Bold);
//    myTextLabel.setColor(sf::Color::Green);
//    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));







    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update(){
    //cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);




    }
}
void animate::render(){
       window.clear();
       Draw();
       window.display();
}



void animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;
            // key pressed
        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::Escape:
                sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                sidebar.save("sidebar.txt");
                window.close();
                break;
            case sf::Keyboard::A:
                cout<<"A PRESSED!\n";
                sidebar[SB_KEY_PRESSED] = "PAN LEFT";
                command = 1;
                break;
            case sf::Keyboard::D:
                cout<<"D PRESSED!\n";
                sidebar[SB_KEY_PRESSED] = "PAN RIGHT";
                command = 2;
                break;
            case sf::Keyboard::W:
                cout<<"W PRESSED!\n";
                sidebar[SB_KEY_PRESSED] = "PAN UP";
                command = 3;
                break;
            case sf::Keyboard::S:
                cout<<"S PRESSED!\n";
                sidebar[SB_KEY_PRESSED] = "PAN DOWN";
                command = 4;
                break;
            case sf::Keyboard::Dash:
                cout<<"DASH PRESSED!\n";
                sidebar[SB_KEY_PRESSED] = "ZOOM OUT";
                command = 5;
                break;
            case sf::Keyboard::Equal:
                cout<<"EQUAL PRESSED!\n";
                sidebar[SB_KEY_PRESSED] = "ZOOM IN";
                command = 6;
                break;
            case sf::Keyboard::R:
                cout<<"R PRESSED!\n";
                sidebar[SB_KEY_PRESSED] = "DEFAULT";
                command = 7;
                break;
            case sf::Keyboard::Num0:
                cout<<"0 PRESSED!\n";
                sidebar[SB_KEY_PRESSED] = "FIT";
                command = 8;
                break;

            case sf::Keyboard::Comma:
            {
                cout<<"COMMA PRESSED!\n";
                double x1;
                double x2;
                cout<<"ENTER NEW X-AXIS MIN: ";
                cin>>x1;
                cout<<"ENTER NEW X-AXIS MAX: ";
                cin>>x2;
                system.reset_x(x1,x2);
            }
                break;
            case sf::Keyboard::Period:
            {
                cout<<"PERIOD PRESSED!\n";
                double y1;
                double y2;
                cout<<"ENTER NEW Y-AXIS MIN: ";
                cin>>y1;
                cout<<"ENTER NEW Y-AXIS MAX: ";
                cin>>y2;
                system.reset_y(y1,y2);
            }
                break;
            case sf::Keyboard::Num1:
            {
                cout<<"1 PRESSED!\n";
                cout<<"ENTER NEW FUNCTION:\t";
                string line;
                getline(cin,line);
                system.reset_function(line);
                sidebar.save("sidebar.txt");
                sidebar[FUNCTION_CHOSEN] = line;
                sidebar.load("sidebar.txt");
                break;
            }
            default:
                break;
            }

            break;
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
             mouseX = event.mouseMove.x;
             mouseY = event.mouseMove.y;
             //Do something with it if you need to...
            break;
        case sf::Event::MouseButtonReleased:
            if(event.mouseButton.button==sf::Mouse::Left){
                mouseX = sf::Mouse::getPosition(window).x;
                mouseY = sf::Mouse::getPosition(window).y;
                if(mouseX>WORK_PANEL){
                    string temp = system.get_equation();
                    int n = 0;
                    if(mouseY>=66&&mouseY<84)
                        n = 1;
                    if(mouseY>=84&&mouseY<102)
                        n = 2;
                    if(mouseY>=102&&mouseY<122)
                        n = 3;
                    if(mouseY>=122&&mouseY<140)
                        n = 4;
                    if(mouseY>=140&&mouseY<159)
                        n = 5;
                    if(mouseY>=159&&mouseY<178)
                        n = 6;
                    if(mouseY>=178&&mouseY<198)
                        n = 7;
                    if(mouseY>=198&&mouseY<216)
                        n = 8;
                    if(mouseY>=216&&mouseY<235)
                        n = 9;
                    if(n!=0){
                        cout<<"LOAD FUNCTION!\n";
                        system.reset_function(sidebar[FUNCTION_CHOSEN+n]);
                        sidebar[FUNCTION_CHOSEN] = sidebar[FUNCTION_CHOSEN+n];
                        sidebar[FUNCTION_CHOSEN+n] = temp;
                    }
                }
            }
//                if (event.mouseButton.button == sf::Mouse::Right)
//                {
//                    sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
//                            mouse_pos_string(window);

//                }
//                else{
//                    sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
//                            mouse_pos_string(window);
//                }
                break;

            default:
                break;
        }
    }

}
void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------------------------- ANIMATE MAIN LOOP EXITING --------------------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
