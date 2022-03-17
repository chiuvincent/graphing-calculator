#include "r_par.h"

R_par::R_par():token(){

}

R_par::R_par(string str):token(str){

}

void R_par::print(){
    cout<<")"<<endl;
}

char R_par::type(){
    return ')';
}
