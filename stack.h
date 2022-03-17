#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "list.h"
#include "linked_list_functions.h"

using namespace std;

template <class T>
class stack{
public:
    class Iterator{
    public:
        friend class stack;
        Iterator(){
            _it = nullptr;
        }
        Iterator(typename list<T>::Iterator other){
            _it = other;
        }
        T operator *(){
            return *_it;
        }
        T* operator ->(){
            return _it;
        }
        friend bool operator ==(const Iterator& left,
                                const Iterator& right){
            return left._it==right._it;
        }
        friend bool operator !=(const Iterator& left,
                                const Iterator& right){
            return !(left==right);
        }
        Iterator& operator++(){
            return ++_it;
        }
        Iterator operator++(int unused){
            return _it++;
        }
    private:
        typename list<T>::Iterator _it;
    };

public:
    stack();

    ~stack();
    stack(const stack<T> &other);
    stack& operator =(const stack<T> &other){
        _l = other._l;
        _top = _l.i_begin();
    }

    typename stack<T>::Iterator push(T item){
        return _l.i_insert_head(item);
    }
    T pop();
    void empty();
    typename stack<T>::Iterator top(){
        _top = _l.i_begin();
        return _top;
    }

    stack<T>::Iterator s_begin() const{
        return _l.i_begin();
    }
    stack<T>::Iterator s_end() const{
        return _l.i_end();
    }

    friend ostream& operator <<(ostream& outs, const stack<T>& stuff){
        typename stack<T>::Iterator it;
        outs<<"H->";
        for(it=stuff.s_begin(); it!=stuff.s_end(); it++){
            outs<<"["<<*it<<"]->";
        }
        outs<<"|||"<<endl;
        return outs;
    }

    bool not_empty(){
        _top = _l.i_begin();
        return (_top!=NULL);
    }

private:
    list<T> _l;
    typename list<T>::Iterator _top;
};

template <class T>
stack<T>::stack(){
    _l.clear_list();
    _top = _l.i_begin();
}

template <class T>
stack<T>::~stack(){
    //does nothing
}

template <class T>
stack<T>::stack(const stack<T> &other){
    _l = other._l;
    _top = _l.i_begin();
}

template <class T>
T stack<T>::pop(){
    _top = _l.i_begin();
    return _l.i_delete_node(_top);
}

template <class T>
void stack<T>::empty(){
    _l.clear_list();
    _top = _l.i_begin();
}

#endif // STACK_H
