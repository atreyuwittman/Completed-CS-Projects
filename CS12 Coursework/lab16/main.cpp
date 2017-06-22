#include <iostream>
#include "SortedSet.h"

using namespace std;

int main(){
    SortedSet set1;
    SortedSet set2;
    SortedSet set3;
    SortedSet set4;
    
    
    set1.push_front(16);
    set1.push_front(16);
    set1.push_front(30);
    set1.push_front(30);
    set1.push_front(30);
    set1.push_front(58);
    set2.push_front(16);
    set2.push_front(58);
    set2.push_front(30);
    cout << set1 << endl;
    cout << set2 << endl;
    set3 = set1 | set2;
    set4 = set1 & set2;
    cout << set3 << endl;
    cout << set4 << endl;
    return 0;
}