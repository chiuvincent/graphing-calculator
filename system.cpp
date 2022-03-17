#include "system.h"
#include <cstring>


System::System(){
}

System::System(string x){
    //set up grid parameters
    x1 = -15;
    y1 = -15;
    x2 = 15;
    y2 = 15;
    cout<<"x1: "<<x1<<"\tx2: "<<x2<<endl;
    cout<<"y1: "<<y1<<"\ty2: "<<y2<<endl;

    dots = 1200;

    //input function
    equation = x;
    e = evaluator(x);
    //generate graph coordinates
    graph = e.graph(x1,x2,dots, minmax);
//    cout<<"Local extremas\t"<<minmax<<endl;

//    for(int i=0; i<dots; i++){
//        cout<<i+1<<":\t"<<graph[i]<<endl;
//    }

    //convert to screen coordinates
    f = new shape[dots];
    for(int i=0; i<dots; i++){
        point f_loc = {graph[i].x, graph[i].y};
        f_loc = f_loc.screen_transform(x1,y1,x2,y2);
        f[i] = shape(f_loc.x,f_loc.y);
    }

    //set up x axis
    x_origin = {x1,0};
    point x_loc = x_origin.screen_transform(x1,y1,x2,y2);
    x_axis = sf::RectangleShape(sf::Vector2f(WORK_PANEL,1.f));
    x_axis.setPosition(sf::Vector2f(x_loc.x,x_loc.y));

    //set up y axis
    y_origin = {0,y2};
    point y_loc = y_origin.screen_transform(x1,y1,x2,y2);
    y_axis = sf::RectangleShape(sf::Vector2f(SCREEN_HEIGHT,1.f));
    y_axis.setPosition(sf::Vector2f(y_loc.x,y_loc.y));
    y_axis.rotate(90.f);

    x_incr = (x2-x1)/3.0;
    y_incr = (y2-y1)/3.0;
}

void System::Step(int command){
    x_incr = (x2-x1)/3.0;
    y_incr = (y2-y1)/3.0;

    if(command==1){ //pan left
        x1-=x_incr;
        x2-=x_incr;
    }
    if(command==2){ //pan right
        x1+=x_incr;
        x2+=x_incr;
    }
    if(command==3){ //pan up
        y1+=y_incr;
        y2+=y_incr;
    }
    if(command==4){ //pan down
        y1-=y_incr;
        y2-=y_incr;
    }
    if(command==5){ //zoom in
        x1-=x_incr;
        x2+=x_incr;
        y1-=y_incr;
        y2+=y_incr;
    }
    if(command==6){ //zoom out
        x1+=x_incr;
        x2-=x_incr;
        y1+=y_incr;
        y2-=y_incr;
    }
    if(command==7){ //reset to default
        x1 = -15;
        y1 = -15;
        x2 = 15;
        y2 = 15;
    }
    if(command==8){ //zoom to fit
        y1 = minmax.x*4/3;
        y2 = minmax.y*4/3;
//        cout<<"extremas:\t"<<minmax<<endl;
    }
    if(command!=0){
        cout<<"x1: "<<x1<<"\tx2: "<<x2<<endl;
        cout<<"y1: "<<y1<<"\ty2: "<<y2<<endl;
        x_origin = {x1,0};
        point x_loc = x_origin.screen_transform(x1,y1,x2,y2);
        x_axis.setPosition(sf::Vector2f(x_loc.x,x_loc.y));

        y_origin = {0,y2};
        point y_loc = y_origin.screen_transform(x1,y1,x2,y2);
        y_axis.setPosition(sf::Vector2f(y_loc.x,y_loc.y));

        graph = e.graph(x1,x2,dots, minmax);
        for(int i=0; i<dots; i++){
            point f_loc = {graph[i].x, graph[i].y};
            f_loc = f_loc.screen_transform(x1,y1,x2,y2);
            f[i] = shape(f_loc.x,f_loc.y);
        }
    }
}


void System::Draw(sf::RenderWindow& window){
    window.clear();
    //draw axis
    window.draw(x_axis);
    window.draw(y_axis);
    //draw graph
    for(int i=0; i<dots; i++){
        f[i].draw(window);
    }
}

void System::reset_x(double new_min, double new_max){
    try{
        if(new_max<=new_min)
            throw 0;
        x1 = new_min;
        x2 = new_max;
        this->Step(100);
        cout<<"RESET SUCCESS!\n";
    }
    catch(int i){
        cout<<"RESET FAILED!\n";
    }
}

void System::reset_y(double new_min, double new_max){
    try{
        if(new_max<=new_min)
            throw 0;
        y1 = new_min;
        y2 = new_max;
        this->Step(100);
        cout<<"RESET SUCCESS!\n";
    }
    catch(int i){
        cout<<"RESET FAILED!\n";
    }
}

void System::reset_function(string x){
    equation = x;
    e = evaluator(x);
    this->Step(7);
}

string System::get_equation(){
    return equation;
}
