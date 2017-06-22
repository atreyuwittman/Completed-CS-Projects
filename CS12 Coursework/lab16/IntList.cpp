#include <iostream>
#include "IntList.h"
#include <ostream>
                                           
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
IntList::IntList(const IntList &cpy){
    if(cpy.head == 0){
        head = 0;
        tail = 0;
        return;
    }
    head = new IntNode(cpy.head->data);
    IntNode * prev = head;
    for(IntNode * cur = cpy.head->next; cur != 0; cur = cur->next){
      IntNode * tmp = new IntNode(cur->data);
      prev->next = tmp;
      prev = prev->next;
    }
    tail = prev;

}
IntList & IntList::operator=(const IntList &rhs){
    if(rhs.head == 0){
        clear();
        return *this;
    }
    if(this == &rhs){
        return *this;
    }
    clear();
    head = new IntNode(rhs.head->data);
    IntNode * prev = head;
    for(IntNode * cur = rhs.head->next; cur != 0; cur = cur->next){
      IntNode * tmp = new IntNode(cur->data);
      prev->next = tmp;
      prev = prev->next;
    }
    tail = prev;
    return *this;
}
void IntList::push_back(int value){
    IntNode * tmp = new IntNode(value);
    if(tail == 0){
        head = tmp;
        tail = tmp;
        return;
    }
    tail-> next = tmp;
    this->tail = tmp;
    
}
void IntList::clear(){
    if (head != 0) {
      pop_front();
   }
   tail = 0;
   head = 0;
}
void IntList::selection_sort(){
    IntNode * i = head;
    for(IntNode* cur1 = i; cur1 != 0; cur1 = cur1->next){
        for(IntNode* cur2 = cur1->next; cur2 != 0; cur2 = cur2->next){
            if(cur2->data < cur1->data){
                swap(cur2->data, cur1->data);
            }
        }
    }
}
void IntList::insert_ordered(int value){
    if(tail == 0){
        push_front(value);
        return;
    }
    if(head->data >= value){
        push_front(value);
        return;
    }
    else if(tail->data <= value){
        push_back(value);
        return;
    }
    else{
    IntNode * prev = head;
    for(IntNode* cur = head->next; cur != 0; cur = cur->next){
        if(value < cur->data){
            IntNode * tmp = new IntNode(value);
            tmp-> next = cur;
            prev->next = tmp;
            prev = cur;
            return;
        }
        prev = cur;
        }
    }
}
void IntList::remove_duplicates(){
    for(IntNode* cur1 = head; cur1 != 0; cur1 = cur1->next){
        IntNode * prev = cur1;
        if(prev->next == 0){
            return;
        }
        for(IntNode* cur2 = cur1->next; cur2 != 0; cur2 = cur2->next){
            if(cur1->data == cur2->data){
                IntNode * tmp = cur2->next;
                delete cur2;
                cur2 = prev;
                prev->next = tmp;
            }
            prev = cur2;
        }
    }
}
ostream & operator<<(ostream &out, const IntList &rhs){
    for(IntNode* cur = rhs.head; cur != 0; cur = cur->next){
        out << cur-> data;
        if(cur->next != 0){
        out << " ";
        }
   }
   return out;
}