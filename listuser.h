#ifndef LISTUSER_H
#define LISTUSER_H
#include "user.h"
class node{
public:
    User person;
    node * next;
    node * prev;
    node(){
        this->next=nullptr;
        this->prev= nullptr;
    }
    node(User aperson):person(aperson){}
};
class listuser
{
public:
    node * head;
        node * tail;
        listuser(){
            head = tail = nullptr;
        }
        node * pushfront(User adddata);
        node * pushback(User adddata);
        void pop_front();
            void pop_back();
            node * getat(int index);
                node * operator [] (int index){
                    return getat(index);
                };
                node * insert(int index, User insertdata);
          void erase(int index);

};

#endif // LISTUSER_H
