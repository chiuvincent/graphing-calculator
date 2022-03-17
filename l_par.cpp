#include "l_par.h"

L_par::L_par():token(){

}

L_par::L_par(string str):token(str){

}

void L_par::print(){
    cout<<"("<<endl;
}

char L_par::type(){
    return '(';
}
