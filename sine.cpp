#include "sine.h"

sine::sine(){

}

sine::sine(string str):token(str){

}

void sine::print(){
    cout<<"sin"<<endl;
}

char sine::type(){
    return 's';
}
