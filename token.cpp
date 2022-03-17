#include "token.h"

token::token()
{
    s = "";
}

token::token(string str){
    s = str;
}

void token::print(){
    cout<<s<<endl;
}

char token::type(){
    return 'T';
}

ostream& operator <<(ostream& outs, const token& stuff){
    outs<<stuff.s;
    return outs;
}

ostream& operator <<(ostream& outs, token* ptr){
    outs<<ptr->s;
    return outs;
}
