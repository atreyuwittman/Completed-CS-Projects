#include <iostream>
#include "SortedSet.h"
using namespace std;

SortedSet::SortedSet(){
    head = 0;
    tail = 0;
}
SortedSet::SortedSet(const SortedSet &cpy): IntList(cpy){
    
}
SortedSet::SortedSet(const IntList &cpy): IntList(cpy){
    this->remove_duplicates();
    this->selection_sort();
}
SortedSet::~SortedSet(){
}
bool SortedSet::in(int data){
    for(IntNode* cur = head; cur != 0; cur = cur->next){
        if(data == cur->data){
            return true;
        }
    }
    return false;
}
SortedSet SortedSet::operator|(SortedSet &rhs){
    SortedSet combined;
    if(this->head == 0 && rhs.head == 0){
        return combined;
    }
    if(this->head == 0){
        for(IntNode* cur = rhs.head; cur != 0; cur = cur->next){
                combined.add(cur->data);
        }
    }
    if(rhs.head == 0){
            for(IntNode* cur = rhs.head; cur != 0; cur = cur->next){
                combined.add(cur->data);
            }
    }
    for(IntNode* cur = rhs.head; cur != 0; cur = cur->next){
        combined.add(cur->data);
    }
    for(IntNode* cur = this->head; cur != 0; cur = cur->next){
        combined.add(cur->data);
    }
    return combined;
}
SortedSet SortedSet::operator&(SortedSet &rhs){
    SortedSet intersection;
    if(rhs.head == 0){
        return intersection;
    }
    if(this->head == 0){
        return intersection;
    }
    IntNode * cur1 = this->head;
    IntNode * cur2 = rhs.head;
    while(cur1 != 0 && cur2 != 0){
        if(cur1->data == cur2->data){
            intersection.add(cur1->data);
            cur1 = cur1->next;
        }
        else{
            if(cur2->data > cur1->data){
                cur1 = cur1->next;
            }
            else{
                cur2 = cur2->next;
            }
        }
    }
    return intersection;
}
void SortedSet::add(int data){
    if(in(data)){
        return;
    }
    if(tail == 0){
        IntList::push_front(data);
        return;
    }
    if(head->data >= data){
        IntList::push_front(data);
        return;
    }
    else if(tail->data <= data){
        IntList::push_back(data);
        return;
    }
    else{
    IntNode * prev = head;
    for(IntNode* cur = head->next; cur != 0; cur = cur->next){
        if(data < cur->data){
            IntNode * tmp = new IntNode(data);
            tmp-> next = cur;
            prev->next = tmp;
            prev = cur;
            return;
        }
        prev = cur;
        }
    }
}
void SortedSet::push_front(int data){
    return add(data);
}
void SortedSet::push_back(int data){
    return add(data);
}
void SortedSet::insert_ordered(int data){
    return add(data); 
}
SortedSet SortedSet::operator|=(SortedSet &rhs){
    SortedSet combined;
    if(this->head == 0 && rhs.head == 0){
        return combined;
    }
    if(this->head == 0){
        for(IntNode* cur = rhs.head; cur != 0; cur = cur->next){
                combined.add(cur->data);
        }
    }
    if(rhs.head == 0){
            for(IntNode* cur = this->head; cur != 0; cur = cur->next){
                combined.add(cur->data);
            }
    }
    for(IntNode* cur = rhs.head; cur != 0; cur = cur->next){
        combined.add(cur->data);
    }
    for(IntNode* cur = this->head; cur != 0; cur = cur->next){
        combined.add(cur->data);
    }
    return combined;
}
SortedSet SortedSet::operator&=(SortedSet &rhs){
    SortedSet intersection;
    if(this->head == 0 || rhs.head == 0){
        return intersection;
    }
    if(rhs.head == 0){
        return intersection;
    }
    if(this->head == 0){
        return intersection;
    }
    IntNode * cur1 = this->head;
    IntNode * cur2 = rhs.head;
    while(cur1 != 0 && cur2 != 0){
        if(cur1->data == cur2->data){
            intersection.add(cur1->data);
            cur1 = cur1->next;
        }
        else{
            if(cur2->data > cur1->data){
                cur1 = cur1->next;
            }
            else{
                cur2 = cur2->next;
            }
        }
    }
    *this = intersection;
    return *this;
}