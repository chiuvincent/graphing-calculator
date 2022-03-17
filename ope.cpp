#include "ope.h"

ope::ope():token(){
    pr = NULL;
    op = "";
}

ope::ope(string str):token(str){
    if(str=="+"||str=="-"){
        pr = 1;
    }
    else if(str=="*"||str=="/"){
        pr = 2;
    }
    else if(str=="^"){
        pr = 3;
    }
    op = str;
}

void ope::print(){
    cout<<op<<endl;
}

char ope::type(){
    return 'o';
}

string ope::operate(){
    return op;
}

int ope::precedence(){
    return pr;
}
