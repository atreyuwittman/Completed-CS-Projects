#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList(){
    head = 0;
    tail = 0;
}
IntList::~IntList(){
    if (head != 0) {
      pop_front();
   }
}
void IntList::display() const{
    for(IntNode* cur = head; cur != 0; cur = cur->next){
        cout << cur-> data;
        if(cur->next != 0){
        cout << " ";
        }
   }
}
void IntList::push_front(int value){
    IntNode * tmp = new IntNode(value);
    tmp-> next = this-> head;
    this->head = tmp;
    if(tail == 0){
        tail = tmp;
    }
}
void IntList::pop_front(){
    IntNode * tmp = head;
    head = head->next;
    delete tmp;
    if(head == 0){
        tail = 0;
    }
}
bool IntList::empty() const{
    if(tail == 0){
    return true;
    }
    else{
        return false;
    }
}
