#include "tangent.h"

tangent::tangent(){

}

tangent::tangent(string str):token(str){

}

void tangent::print(){
    cout<<"tan"<<endl;
}

char tangent::type(){
    return 't';
}
