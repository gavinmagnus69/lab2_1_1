#ifndef LISTCALLS_H
#define LISTCALLS_H
#include "calls.h"
class node2{
public:
    Calls call;
    node2 * next;
    node2 * prev;
    node2(Calls acall):call(acall){}
    node2(){
        this->next = nullptr;
        this->prev = nullptr;

    }
};
class listcalls
{
public:
    node2 * head;
    node2* tail;
    listcalls(){
        head=tail=nullptr;
    };
    node2 * pushfront(Calls adddata);
    node2 * pushback(Calls adddata);
    void pop_front();
    void pop_back();
    node2 * getat(int index);
    node2 * operator [] (int index){
        return getat(index);
    };
    node2 * insert(int index, Calls insertdata);
    void erase(int index);
};

#endif // LISTCALLS_H
