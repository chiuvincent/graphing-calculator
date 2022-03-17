#include "cosine.h"

cosine::cosine(){

}

cosine::cosine(string str):token(str){

}

void cosine::print(){
    cout<<"cos"<<endl;
}

char cosine::type(){
    return 'c';
}
