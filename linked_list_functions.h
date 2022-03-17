#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
struct node{
public:
    T _item;
    node<T> *_next;

    node(T item = T(), node<T> *next = NULL):_item(item), _next(next){
        //sets T _item to the default value T(), last object in list to null
    }
    friend ostream& operator <<(ostream& outs, const node<T>& print_me){
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

template <class T>
void _print_list(ostream& outs, node<T> *head_ptr);
template <class T>
void _print_list_backwards(node<T>* head_ptr);
template <class T>
node<T>* _search_list(node<T>* head_ptr, T key);
template <class T>
node<T>* _insert_head(node<T>* &head_ptr, const T& item);
template <class T>
node<T>* _insert_after(node<T>* &after_this, const T& item);
template <class T>
node<T>* _insert_before(node<T>* &head_ptr, node<T>* before_this, const T& item);
template <class T>
node<T>* _previous_node(node<T>* head_ptr, node<T>* prev_to_this);
template <class T>
T _delete_node(node<T>* &head_ptr, node<T>* delete_this);
template <class T>
node<T>* _copy_list(node<T>* head_ptr);
template <class T>
void _clear_list(node<T>* &head_ptr);
template <class T>
T& _at(node<T>* head_ptr, int pos);
template <class T>
node<T>* _insert_sorted(node<T>* &head_ptr, T item, bool ascending=true);
template <class T>
node<T>* WhereThisGoes(node<T>* head_ptr, T item, bool ascending=true);
template <class T>
node<T>* _last_node(node<T>* head_ptr);

template <class T>
void _print(node<T> *head_ptr);

template <class T>
void _print_list(ostream& outs, node<T> *head_ptr){
    node<T> *walker = head_ptr;
    outs<<"H->";
    while(walker!=NULL){
        outs<<*walker;
        walker = walker->_next;
    }
    outs<<"|||"<<endl;
}

template <class T>
void _print_list_backwards(node<T>* head_ptr){
    node<T>* walker = _last_node(head_ptr);
    cout<<"H->";
    while(walker!=head_ptr){
        cout<<*walker;
        walker = _previous_node(head_ptr, walker);
    }
    cout<<"|||"<<endl;
}

template <class T>
node<T>* _search_list(node<T>* head_ptr, T key){
    while(head_ptr){
        if(head_ptr->_item==key){
            return head_ptr;
        }
        head_ptr = head_ptr->_next;
    }
    return NULL;
}

template <class T>
node<T>* _insert_head(node<T>* &head_ptr, const T& item){
    //1: temp points to new node obj
    node<T> *temp = new node<T>(item);
    //2: new node obj's ptr points to first object in list
    temp->_next = head_ptr;
    //3: head pointer points to new node obj
    head_ptr = temp;
    return head_ptr;
}

template <class T>
node<T>* _insert_after(node<T>* &after_this, const T& item){
    if(after_this!=NULL){
        return _insert_head(after_this->_next, item);
    }
    return NULL;
//    else{
//        cout<<"\nDEAD END\n";
//    }
}

template <class T>
node<T> *_insert_before(node<T>* &head_ptr, node<T>* before_this, const T& item){
    node<T>* here = _previous_node(head_ptr, before_this);
    if(here!=NULL){
        return _insert_after(here, item);
    }
    else{
        return _insert_head(head_ptr, item);
    }
//    _insert_after(before_this,before_this->_item);
//    before_this->item = item;
}

template <class T>
node<T>* _previous_node(node<T>* head_ptr, node<T>* before_this){
    //    if(head_ptr==before_this){
    //        //cout<<"\nBEFORE THE BEGINNING\n";
    //        return NULL;
    //    }
    //    node<T>* walker = head_ptr;
    //    while(walker && walker->_next!=before_this){ //checks for empty list and walking off cursor
    //        assert(walker->_next!=NULL); //makes sure program quits if before_this DNE
    //        walker = walker->_next;
    //    }
    //    return walker;
    try{
        if(head_ptr==before_this){
            throw 0;
        }
        node<T>* walker = head_ptr;
        while(walker && walker->_next!=before_this){ //checks for empty list and walking off cursor
            if(walker->_next==NULL){
                throw 'c';
            }
            walker = walker->_next;
        }
        return walker;
    }
    catch(int n){
        cout<<"\nERROR: NODE BEFORE HEAD\n";
    }
    catch(char c){
        cout<<"\nERROR: WALKER OUT OF BOUNDS\n";
    }

}

template <class T>
T _delete_node(node<T>* &head_ptr, node<T>* delete_this){
    if(!head_ptr){
        return NULL;
    }
    T item = delete_this->_item;
    if(delete_this==head_ptr){
        head_ptr = head_ptr->_next;
    }
    else{
        node<T>* before =_previous_node(head_ptr, delete_this);
        before->_next = delete_this->_next;
    }
    delete delete_this;
    return item;
}

template <class T>
node<T>* _copy_list(node<T>* head_ptr){
    if(head_ptr==NULL){ //check for empty list
        return NULL;
    }
    node<T>* copy;
    copy = NULL;
    node<T>* walker = head_ptr;
    while(walker->_next){
        walker = walker->_next; //goes to end of list
    }
    while(walker!=head_ptr){
        _insert_head(copy, walker->_item);
        walker = _previous_node(head_ptr, walker);
    }
    _insert_head(copy, walker->_item);
    return copy;
}

template <class T>
void _clear_list(node<T>* &head_ptr){
    while(head_ptr){
        T temp;
        temp = _delete_node(head_ptr,head_ptr);
    }
}

template <class T>
T& _at(node<T>* head_ptr, int pos){
//    assert(head_ptr); //assert empty array
//    node<T>* walker = head_ptr;
//    for(int i=0; i<pos; i++){
//        walker = walker->_next;
//        assert(walker); //assert if index is out of bounds
//    }
//    return walker->_item;
    try{
        if(!head_ptr){
            throw 0;
        }
        node<T>* walker = head_ptr;
        for(int i=0; i<pos; i++){
            walker = walker->_next;
            if(!walker){
                throw 'c';
            }
        }
        return walker->_item;
    }
    catch(int n){
        cout<<"ERROR: EMPTY ARRAY"<<endl;
    }
    catch(char c){
        cout<<"ERROR: INDEX "<<pos<<" IS OUT OF BOUNDS"<<endl;
    }
}

template <class T>
node<T>* _insert_sorted(node<T>* &head_ptr, T item, bool ascending=true){
    node<T>* walker = head_ptr;
    while(walker->_next && item>walker->_item){
        walker = walker->_next;
    }
    if(item>walker->_item){
        return _insert_after(walker, item);
    }
    else{
        return _insert_before(head_ptr,walker,item);
    }
}

template <class T>
node<T>* WhereThisGoes(node<T>* head_ptr, T item, bool ascending=true){
    node<T>* walker = head_ptr;
    while(walker->_next && item>walker->_item){
        walker = walker->_next;
    }
    if(item>walker->_item){
        return walker;
    }
    else if(walker==head_ptr){
        return head_ptr; //have to use insert head
    }
    else{
        return _previous_node(head_ptr, walker);
    }
}

template <class T>
node<T>* _last_node(node<T>* head_ptr){
    if(!head_ptr){
        return NULL;
    }
    while(head_ptr->_next){
        head_ptr = head_ptr->_next;
    }
    return head_ptr;
}

template <class T>
void _print(node<T> *head_ptr){
    node<T> *walker = head_ptr;
    cout<<"H->";
    while(walker!=NULL){
        cout<<*walker;
        walker = walker->_next;
    }
    cout<<"|||"<<endl;
}

#endif // LINKED_LIST_FUNCTIONS_H
