/*
 * Author: Vincent Chiu
 * Project: Graphing Calculator
 * Purpose: Using SFML, Shunting Yard, RPN to graph functions
 * able to handle sines, cosines, tangents, logs, and unary
 * operator. Able to zoom in, out, pan left, right, up, down
 */
#include <iostream>
#include <string>
#include <cstring>
#include "evaluator.h"
#include "linked_list_functions.h"
#include "point.h"
#include "animate.h"

using namespace std;

void calculator();
void graph_coordinates(int points);

int main()
{
    animate game;
    game.run();
    cout<<endl<<endl<<"-------------------------- MAIN EXITING --------------------------"<<endl;
    return 0;
}

void calculator(){
    //input
    string x;
    cout<<"ENTER EQUATION:\t";
    getline(cin,x);
    while(x[0]!='x'&&x[0]!='X'){
        //compute and output
        evaluator e(x);
        cout<<"EVALUATE = "<<e.calculate()<<endl<<endl;

        cout<<"ENTER EQUATION:\t";
        getline(cin,x);
    }
}

void graph_coordinates(int points){
        //input
        string x;
        cout<<"ENTER FUNCTION:\t";
        getline(cin,x);
        point minmax;
        point* coord;
        while(x[0]!='!'){
            //compute and output
            evaluator e(x);
            coord = e.graph(-50,50,points, minmax);
            for(int i=0; i<points; i++)
                cout<<i+1<<"\t"<<coord[i]<<endl;
            cout<<"Local extremas\t"<<minmax<<endl;
            cout<<"ENTER EQUATION:\t";
            getline(cin,x);
        }
}
