#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cassert>
#include "linked_list_functions.h"

using namespace std;

template <class T>
class list
{
public:
    class Iterator //a ptr can automatically become an iterator
                   //but a iterator cannot become a pointer
    {
    public:
        friend class list;

        Iterator(){
            ptr = NULL;
        }

        Iterator(node<T>* other){
            ptr = other;
        }

        T& operator *(){
            return ptr->_item;
        }

        T* operator ->(){
            return ptr;
        }

        friend bool operator ==(const Iterator& left, const Iterator& right){
            return (left.ptr == right.ptr);
        }

        friend bool operator !=(const Iterator& left, const Iterator& right){
            return !(left==right);
        }

        Iterator& operator++(){
            ptr = ptr->_next;
            return ptr;
        }

        Iterator operator++(int unused){
            node<T>* temp = ptr;
            ptr = ptr->_next;
            return temp;
        }

    private:
        node<T>* ptr;
    };

public:
    list();

    ~list();
    list(const list<T> &other);
    list& operator =(const list<T>& other){
        _clear_list(head);
        head = _copy_list(other.head);
        last = head;
        size = other.size;
    }

    T& operator[](int index){
        return _at(head, index);
    }
    friend ostream& operator <<(ostream& outs, const list<T>& stuff){
        _print_list(outs, stuff.head);
        return outs;
    }

//    friend ostream& operator <<(ostream& outs, const Iterator<T>& stuff){
//        _print_list(outs, stuff.ptr);
//        return outs;
//    }
    void clear_list();
    void print() const;

    list<T>::Iterator i_insert_head(T item){
        return insert_head(item);
    }
    list<T>::Iterator i_insert_after(Iterator after_this, T item){
        return insert_after(after_this.ptr, item);
    }
    list<T>::Iterator i_insert_before(Iterator before_this, T item){
        return insert_before(before_this.ptr, item);
    }
    list<T>::Iterator i_insert_sorted(T item){
        return insert_sorted(item);
    }

    T i_delete_node(Iterator delete_this){
        return delete_node(delete_this.ptr);
    }
    list<T>::Iterator i_search(const T& key){
        return search(key);
    }
    list<T>::Iterator i_previous_node(Iterator before_this){
        return previous_node(before_this.ptr);
    }
    list<T>::Iterator i_begin() const{
        return head;
    }
    list<T>::Iterator i_end() const{
        return NULL;
    }
    list<T>::Iterator i_last_node() const{
        return _last_node(head);
    }

//    list<T>::Iterator i_walker(int index){
//        return walker(index);
//    }
//    int i_walker(Iterator walk){
//        return walker(walk.ptr);
//    }

private:
    node<T>* head;
    node<T>* last;
    int size;

    node<T> *insert_head(T item);
    node<T> *insert_after(node<T> *after_this, T item);
    node<T> *insert_before(node<T>* before_this, T item);
    node<T> *insert_sorted(T item);
    T delete_node(node<T>* delete_this);
    node<T>* search(const T &key);
    node<T>* previous_node(node<T>* before_this);
    node<T>* begin() const;
    node<T>* end() const;
    node<T>* walker(int c);
    int walker(node<T>* w);
};

template <class T>
list<T>::list(){
    head = NULL;
    last = head;
    size = 0;
}

template <class T>
list<T>::~list(){
    _clear_list(head);
    size = 0;
}

template <class T>
list<T>::list(const list<T> &other){
    head = _copy_list(other.head);
    last = head;
    size = other.size;
}

template <class T>
node<T>* list<T>::insert_head(T item){
    size++;
    node<T>* temp = _insert_head(head, item);
    last = _last_node(head);
    return temp;
}

template <class T>
node<T>* list<T>::insert_after(node<T> *after_this, T item){
    size++;
    node<T>* temp =  _insert_after(after_this, item);
    last = _last_node(head);
    return temp;
}

template <class T>
node<T>* list<T>::insert_before(node<T> *before_this, T item){
    size++;
    node<T>* temp = _insert_before(head, before_this, item);
    last = _last_node(head);
    return temp;
}

template <class T>
node<T>* list<T>::insert_sorted(T item){
    size++;
    node<T>* temp = _insert_sorted(head, item, true);
    last = _last_node(head);
    return temp;
}

template <class T>
T list<T>::delete_node(node<T> *delete_this){
    if(size!=0){
        size--;
    }
    T temp = _delete_node(head, delete_this);
    last = _last_node(head);
    return temp;
}
template <class T>
void list<T>::clear_list(){
    _clear_list(head);
    last = head;
    size = 0;
}

template <class T>
void list<T>::print() const{
    _print(head);
}

template <class T>
node<T>* list<T>::search(const T &key){
    return _search_list(head, key);
}

template <class T>
node<T>* list<T>::previous_node(node<T> *before_this){
    return _previous_node(head, before_this);
}

template <class T>
node<T>* list<T>::begin() const{
    return head;
}

template <class T>
node<T>* list<T>::end() const{
    return _last_node(head);
}

template <class T>
node<T>* list<T>::walker(int c){
    node<T>* w = head;
    for(int i=0; i<c; i++){
        w = w->_next;
    }
    return w;
}

template <class T>
int list<T>::walker(node<T> *w){
    int index = 0;
    node<T>* walker = head;
    while(walker){
        if(walker==w){
            return index;
        }
        walker = walker->_next;
        index++;
    }
    return NULL;
}


#endif // LIST_H
