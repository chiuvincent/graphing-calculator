#include "shunting_yard.h"

shunting_yard::shunting_yard(){

}

shunting_yard::shunting_yard(queue<token *> infix){
    input = infix;
}

queue<token*> shunting_yard::postfix(){
    stack<token*> s;
    token* t = input.pop();
    while(input.not_empty()){
        if(t->type()=='n'){
            num* n = static_cast<num*>(t);
            rpn.push(n);
        }
        else if(t->type()=='('){
            L_par* L = static_cast<L_par*>(t);
            s.push(L);
        }
        else if(t->type()==')'){
            token* temp = s.pop();
            while(temp->type()!='('){
                rpn.push(temp);
                temp = s.pop();
            }
            if(s.not_empty()){ //pushes function after parentheses
                temp = s.pop();
                if(temp->type()=='s'||temp->type()=='c'||temp->type()=='t'||temp->type()=='l'){
                    rpn.push(temp);
                }
                else{
                    s.push(temp);
                }
            }
        }
        else if(t->type()=='o'){
            if(s.not_empty()){
                bool not_empty = s.not_empty();
                token* temp = s.pop();
                ope* o = static_cast<ope*>(t);
                bool exit = false;
                while(!exit&&not_empty&&temp->type()=='o'){
                    ope* stackop = static_cast<ope*>(temp);
                    if(o->precedence()<=stackop->precedence()){
                        rpn.push(stackop);
                        not_empty = s.not_empty();
                        if(not_empty){
                            temp = s.pop();
                        }
                    }
                    else{
                        s.push(stackop);
                        exit = true;
                    }
                }
                if(temp->type()!='o'){
                    s.push(temp);
                }
                s.push(o);
            }
            else{
                ope* o = static_cast<ope*>(t);
                s.push(o);
            }
        }
        else if(t->type()=='s'||t->type()=='c'||t->type()=='t'||t->type()=='l'){
            s.push(t); //push function into stack
        }
        t = input.pop();

    }
    while(s.not_empty()){
        rpn.push(s.pop());
    }
    return rpn;
}
