#include "point.h"

point point::screen_transform(double x1, double y1, double x2, double y2){
    double new_x = WORK_PANEL*(x-x1)/(x2-x1);
    double new_y = -SCREEN_HEIGHT*((y-y1)/(y2-y1)-1);
    return {new_x,new_y};
}

point point::rectangular_transform(double x1, double y1, double x2, double y2){
    double new_x = x/WORK_PANEL*(x2-x1)+x1;
    double new_y = (1-y/SCREEN_HEIGHT)*(y2-y1)+y1;
    return {new_x,new_y};
}

ostream& operator <<(ostream& outs, const point& stuff){
    outs<<"("<<stuff.x<<","<<stuff.y<<")\n";
    return outs;
}
