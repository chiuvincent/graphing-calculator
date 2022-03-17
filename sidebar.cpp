#include "sidebar.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include "constants.h"

Sidebar::Sidebar(){

}

Sidebar::Sidebar(float left, float width):_left(left), _width(width){
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(50);

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(105,105,105)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("arial.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(12);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color::White);

    ////this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    items.push_back("sidebar sample text");
    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i=0 ; i<30; i++){
        items.push_back("");
//        items.push_back(to_string(i));
    }
    cout<<"Sidebar: CTOR: Exit."<<endl;
}

void Sidebar::draw(sf::RenderWindow& window){
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    float height = 10;

    for (vector<string>::iterator it = items.begin();
                                it!= items.end(); it++){
        bool blank = false;
        if ((it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else{
            sb_text.setString(it->c_str());
        }
        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(sb_text);
    }
}

string& Sidebar::operator [](int index){
    return items[index];
}

void Sidebar::insert(string equation){
    items.push_back(equation);
}

void Sidebar::save(string fileName){
    try{
        ofstream outFile;
        outFile.open(fileName);
        if(outFile.fail()){
            throw 0;
        }
        for(int i=FUNCTION_CHOSEN; i<items.size(); i++){
            if(items[i]!="")
                outFile<<items[i]<<endl;
        }
        outFile.close();
        cout<<endl<<"FILE SAVE SUCCESS."<<endl;
    }
    catch(int o){
        cout<<endl<<"FILE SAVE FAILED."<<endl;
    }
}

void Sidebar::load(string fileName){
    try{
        ifstream inFile;
        inFile.open(fileName);
        if(inFile.fail()){
            throw 0;

        }
        string line;
        for(int i=1; i<10;i++){
            getline(inFile,line);
            if(line!="")
                items[FUNCTION_CHOSEN+i] = line;
        }
        inFile.close();
        cout<<endl<<"FILE LOAD SUCCESS."<<endl;
    }
    catch(int o){
        cout<<endl<<"FILE LOAD FAILED."<<endl;
    }


}
