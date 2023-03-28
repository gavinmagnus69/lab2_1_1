#include "listuser.h"


    node * listuser::pushfront(User adddata) {
            node *ptr = new node(adddata);

            ptr->next = head;
            if (head != nullptr) {
                head->prev = ptr;
            }
            if (tail == nullptr) {
                tail = ptr;
            }

            head = ptr;
            return ptr;

    }
    node * listuser::pushback(User adddata){
            node * ptr = new node(adddata);
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
    void listuser::pop_front(){
            if(head == nullptr){
                return ;
            }
            node * ptr = head->next;
            if(ptr!= nullptr){
                ptr->prev = nullptr;
            }
            else{
                tail = nullptr;
            }
            delete head;
            head = ptr;

        }
        void listuser::pop_back(){
            if(tail==nullptr){
                return;
            }
            node * ptr = tail->prev;
            if(ptr!= nullptr){
                ptr->next = nullptr;
            }
            else{
                head = nullptr;

            }
            delete tail;
            tail = ptr;

        }
        node * listuser::getat(int index){
                node * ptr = head;
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

            node * listuser::insert(int index, User insertdata){
                    node * right = getat(index);
                    if(right == nullptr){
                        return pushback(insertdata);

                    }
                    node * left = right->prev;
                    if(left==nullptr){
                        return pushfront(insertdata);
                    }
                    node * ptr = new node(insertdata);
                    ptr->prev = left;
                    ptr->next = right;
                    right->prev = ptr;
                    left->next = ptr;
                    return ptr;
                }
                void listuser::erase(int index){
                    node * ptr = getat(index);
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
                    node * left = ptr->prev;
                    node * right = ptr->next;
                    left->next= right;
                    right->prev=left;
                    delete ptr;
                    return;
                }
