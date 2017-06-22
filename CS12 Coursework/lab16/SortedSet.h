#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

#include <iostream>
#include "IntList.h"

using namespace std;

class SortedSet : public IntList{
    public:
        SortedSet();
        SortedSet(const SortedSet &cpy);
        SortedSet(const IntList &cpy);
        ~SortedSet();
        bool in(int data);
        SortedSet operator|(SortedSet & rhs);
        SortedSet operator&(SortedSet & rhs);
        void add(int data);
        void push_front(int data);
        void push_back(int data);
        void insert_ordered(int data);
        SortedSet operator|=(SortedSet & rhs);
        SortedSet operator&=(SortedSet & rhs);
};
#endif