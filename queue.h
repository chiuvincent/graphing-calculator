#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "list.h"
#include "linked_list_functions.h"

using namespace std;

template <class T>
class queue{
public:
    class Iterator{
    public:
        friend class queue;
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
    queue();

    ~queue();
    queue(const queue<T> &other);
    queue& operator =(const queue<T> &other){
        _l = other._l;
        _front = _l.i_begin();
    }

//    //new function!
//    T& operator[](int index){
//        return _l[index];
//    }

    typename queue<T>::Iterator push(T item){
        _rear = _l.i_last_node();
        if(_rear==NULL){
            return _l.i_insert_head(item);
        }
        else{
            return _l.i_insert_after(_rear,item);
        }
    }
    T pop();
    void empty();
    typename queue<T>::Iterator front(){
        _front = _l.i_begin();
        return _front;
    }

    queue<T>::Iterator q_begin() const{
        return _l.i_begin();
    }
    queue<T>::Iterator q_end() const{
        return _l.i_end();
    }

    friend ostream& operator <<(ostream& outs, const queue<T>& stuff){
        typename queue<T>::Iterator it;
        outs<<"H->";
        for(it=stuff.q_begin(); it!=stuff.q_end(); it++){
            outs<<"["<<*it<<"]->";
        }
        outs<<"|||"<<endl;
        return outs;
    }

    bool not_empty(){
        return (_front!=NULL);
    }

private:
    list<T> _l;
    typename list<T>::Iterator _front;
    typename list<T>::Iterator _rear;
};

template <class T>
queue<T>::queue(){
    _l.clear_list();
    _front = _l.i_begin();
    _rear = _l.i_last_node();
}

template <class T>
queue<T>::~queue(){
    //does nothing
}

template <class T>
queue<T>::queue(const queue<T> &other){
    _l = other._l;
    _front = _l.i_begin();
    _rear = _l.i_last_node();
}

template <class T>
T queue<T>::pop(){
    _front = _l.i_begin();
    return _l.i_delete_node(_front);
}

template <class T>
void queue<T>::empty(){
    _l.clear_list();
    _front = _l.i_begin();
    _rear = _l.i_last_node();
}
#endif // QUEUE_H
