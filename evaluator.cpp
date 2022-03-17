#include "evaluator.h"

evaluator::evaluator(){

}

evaluator::evaluator(string str){
    s = str;
}

double evaluator::calculate(){
    queue<token*> input;
    int size = s.length();
    for(int i=0; i<size; i++){
//        cout<<"s["<<i<<"] = "<<s[i]<<endl;
        if(s[i]=='s'&&s[i+1]=='i'&&s[i+2]=='n'){
            i = i+2;
            input.push(new sine("sin"));
        }
        else if(s[i]=='c'&&s[i+1]=='o'&&s[i+2]=='s'){
            i = i+2;
            input.push(new cosine("cos"));
        }
        else if(s[i]=='t'&&s[i+1]=='a'&&s[i+2]=='n'){
            i = i+2;
            input.push(new tangent("tan"));
        }
        else if(s[i]=='l'&&s[i+1]=='n'){
            i++;
            input.push(new natural_log("ln"));
        }

        //unary operator
        else if(s[i]=='-'&&s[i+1]=='-'){ //--
            i++;
            input.push(new ope("+"));
        }
        else if(s[i]=='-'&&s[i+1]=='+'){ //-+
            i++;
            input.push(new ope("-"));
        }
        else if(s[i]=='+'&&s[i+1]=='-'){ //+-
            i++;
            input.push(new ope("-"));
        }
        else if(s[i]=='-'&&s[i+1]=='('&&s[i+2]=='-'){ //-(-
            i+=2;
            input.push(new ope("+"));
            input.push(new L_par("("));
        }
        else if(s[i]=='+'&&s[i+1]=='('&&s[i+2]=='-'){ //+(-
            i+=2;
            input.push(new ope("-"));
            input.push(new L_par("("));
        }
        else if(s[i]=='-'&&s[i+1]=='('&&s[i+2]=='+'){ //-(+
            i+=2;
            input.push(new ope("-"));
            input.push(new L_par("("));
        }//end of unary operator
        else if(s[i]=='-'||s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
            input.push(new ope(s.substr(i,1)));
        }
        else if(s[i]=='('){
            input.push(new L_par("("));
        }
        else if(s[i]==')'){
            input.push(new R_par(")"));
        }
        else if((s[i]>=48&&s[i]<=57) || s[i]=='.'){
            int l = 0;
            int t = i;
            while(t<size&&((s[t]>=48&&s[t]<=57)||s[t]=='.')){
                l++;
                t++;
            }
            input.push(new num(s.substr(i,l)));
            i = t-1;
        }
        else if(s[i]=='p'&&s[i+1]=='i'){
            i = i+1;
            input.push(new num(to_string(M_PI)));
        }
    }
    cout<<"\nINFIX\n"<<input<<endl;
    shunting_yard sh(input);
    queue<token*> postfix = sh.postfix();
    cout<<"POSTFIX\n"<<postfix<<endl;
    RPN r(postfix);
    return r.compute();
}

double evaluator::calculate(double x){
    queue<token*> input;
    int size = s.length();
    for(int i=0; i<size; i++){
        if(s[i]=='x'){ //plug in double for x
            input.push(new num(to_string(x)));
        }
        else if(s[i]=='s'&&s[i+1]=='i'&&s[i+2]=='n'){
            i = i+2;
            input.push(new sine("sin"));
        }
        else if(s[i]=='c'&&s[i+1]=='o'&&s[i+2]=='s'){
            i = i+2;
            input.push(new cosine("cos"));
        }
        else if(s[i]=='t'&&s[i+1]=='a'&&s[i+2]=='n'){
            i = i+2;
            input.push(new tangent("tan"));
        }
        else if(s[i]=='l'&&s[i+1]=='n'){
            i++;
            input.push(new natural_log("ln"));
        }
        //unary operator
        else if(s[i]=='-'&&s[i+1]=='-'){ //--
            i++;
            input.push(new ope("+"));
        }
        else if(s[i]=='-'&&s[i+1]=='+'){ //-+
            i++;
            input.push(new ope("-"));
        }
        else if(s[i]=='+'&&s[i+1]=='-'){ //+-
            i++;
            input.push(new ope("-"));
        }
        else if(s[i]=='-'&&s[i+1]=='('&&s[i+2]=='-'){ //-(-
            i+=2;
            input.push(new ope("+"));
            input.push(new L_par("("));
        }
        else if(s[i]=='+'&&s[i+1]=='('&&s[i+2]=='-'){ //+(-
            i+=2;
            input.push(new ope("-"));
            input.push(new L_par("("));
        }
        else if(s[i]=='-'&&s[i+1]=='('&&s[i+2]=='+'){ //-(+
            i+=2;
            input.push(new ope("-"));
            input.push(new L_par("("));
        }//end of unary operator
        else if(s[i]=='-'||s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
            input.push(new ope(s.substr(i,1)));
        }
        else if(s[i]=='('){
            input.push(new L_par("("));
        }
        else if(s[i]==')'){
            input.push(new R_par(")"));
        }
        else if((s[i]>=48&&s[i]<=57) || s[i]=='.'){
            int l = 0;
            int t = i;
            while(t<size&&((s[t]>=48&&s[t]<=57)||s[t]=='.')){
                l++;
                t++;
            }
            input.push(new num(s.substr(i,l)));
            i = t-1;
        }
        else if(s[i]=='p'&&s[i+1]=='i'){
            i = i+1;
            input.push(new num(to_string(M_PI)));
        }
    }
    shunting_yard sh(input);
    queue<token*> postfix = sh.postfix();
    RPN r(postfix);
    return r.compute();
}

point* evaluator::graph(double min, double max, int dots, point& minmax){
    try{
        if(min>=max) throw 0;
        //create coordinate array
        point* coord = new point[dots];
        double incr = (max-min)/(dots-1);
        int i = 0; //index
        //initialize local min and max
        double local_max = this->calculate(min);
        double local_min = local_max;

        for(double d=min; d<=max; d+=incr){ //should be same as (i=0; i<dots; i++)
            double y = this->calculate(d); //calculates y value
            if(y>local_max){
                local_max = y;
            }
            if(y<local_min){
                local_min = y;
            }
            coord[i] = {d,y};
            i++;
        }
        minmax = {local_min,local_max};

//        for(int j=0; j<dots; j++)
//            cout<<coord[j]<<endl;

        return coord;
    }
    catch(int o){
        cout<<"ERROR: Lower Bound >= Upper Bound\n";
    }
}
