#include "rpn.h"

RPN::RPN(){

}

RPN::RPN(queue<token *> in){
    input = in;
}

double RPN::compute(){
    stack<double> result;
    token* t = input.pop();
    while(input.not_empty()){
        if(t->type()=='n'){
            num* n = static_cast<num*>(t);
            result.push(n->number());
        }
        else if(t->type()=='o'){
//            double second = 0;
//            double first = 0;
//            if(result.not_empty())
//                second = result.pop();
//            if(result.not_empty())
//                first = result.pop();
            double second = result.pop();
            double first = result.pop();
            string o = (static_cast<ope*>(t))->operate();
            if(o=="+"){
                result.push(first+second);
            }
            else if(o=="-"){
                result.push(first-second);
            }
            else if(o=="*"){
                result.push(first*second);
            }
            else if(o=="/"){
                result.push(first/second);
            }
            else if(o=="^"){
                result.push(pow(first,second));
            }
            else{
                cout<<"Unrecognized symbol."<<endl;
            }
        }
        else if(t->type()=='s'){
            double constant = result.pop();
            result.push(sin(constant));
        }
        else if(t->type()=='c'){
            double constant = result.pop();
            result.push(cos(constant));
        }
        else if(t->type()=='t'){
            double constant = result.pop();
            result.push(tan(constant));
        }
        else if(t->type()=='l'){
            double constant = result.pop();
            result.push(log(constant));
        }
        else{
            cout<<"\nUnrecognized token."<<endl;
        }
        t = input.pop();
    }
    return result.pop();
}
