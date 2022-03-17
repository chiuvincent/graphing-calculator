#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <cstring>

using namespace std;

class token
{
public:
    token();
    token(string str);

    virtual void print();
    virtual char type();

    friend ostream& operator <<(ostream& outs, const token& stuff);
    friend ostream& operator <<(ostream& outs, token* ptr);

private:
    string s;
};

#endif // TOKEN_H
