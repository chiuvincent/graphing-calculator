#include "natural_log.h"

natural_log::natural_log(){

}

natural_log::natural_log(string str):token(str){

}

void natural_log::print(){
    cout<<"ln"<<endl;
}

char natural_log::type(){
    return 'l';
}
