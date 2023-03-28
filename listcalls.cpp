#include "listcalls.h"

node2 * listcalls::pushfront(Calls adddata) {
        node2 *ptr = new node2(adddata);

        ptr->next = head;
        if (head != nullptr) {
            head->prev = ptr;
        }
        if (tail == nullptr) {
            tail = ptr;
        }

        head = ptr;
        return ptr;
        //ptr->prev = nullptr;


    }
    node2 * listcalls::pushback(Calls adddata){
        node2 * ptr = new node2(adddata);
        ptr->prev = tail;
        if(tail!=nullptr){
            tail->next = ptr;
        }
        if(head == nullptr){
            head = ptr;
        }
        tail = ptr;
        return ptr;
    }
    void listcalls::pop_front(){
        if(head == nullptr){
            return ;
        }
        node2 * ptr = head->next;
        if(ptr!= nullptr){
            ptr->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
        delete head;
        head = ptr;

    }
    void listcalls::pop_back(){
        if(tail==nullptr){
            return;
        }
        node2 * ptr = tail->prev;
        if(ptr!= nullptr){
            ptr->next = nullptr;
        }
        else{
            head = nullptr;

        }
        delete tail;
        tail = ptr;

    }
    node2 * listcalls::getat(int index){
        node2 * ptr = head;
        int n = 0;
        while(n!= index){
            if(ptr == nullptr){
                return ptr;

            }
            ptr = ptr->next;
            n++;
        }
        return ptr;

    }

    node2 * listcalls::insert(int index, Calls insertdata){
        node2 * right = getat(index);
        if(right == nullptr){
            return pushback(insertdata);

        }
        node2 * left = right->prev;
        if(left==nullptr){
            return pushfront(insertdata);
        }
        node2 * ptr = new node2(insertdata);
        ptr->prev = left;
        ptr->next = right;
        right->prev = ptr;
        left->next = ptr;
        return ptr;
    }
    void listcalls::erase(int index){
        node2 * ptr = getat(index);
        if(ptr == nullptr){
            return;
        }
        if(ptr->prev==nullptr){
            pop_front();
            return;
        }
        if(ptr->next==nullptr){
            pop_back();
            return;
        }
        node2 * left = ptr->prev;
        node2 * right = ptr->next;
        left->next= right;
        right->prev=left;
        delete ptr;
        return;
    }
