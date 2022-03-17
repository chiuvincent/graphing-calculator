#include "num.h"

num::num():token(){
    d = NULL;
}

num::num(string str):token(str){
    d = stod(str);
}

void num::print(){
    cout<<d<<endl;
}

char num::type(){
    return 'n';
}

double num::number(){
    return d;
}


