#include <iostream> 
#include "IntVector.h"
using namespace std;

int main() {
    IntVector arr1(20,0);
    
    for(unsigned int i = 0; i < arr1.size(); i++){
        arr1.at(i) = i;
    }
    cout << arr1.capacity() << endl << endl;
    arr1.resize(30);
    for(unsigned int i = 0; i < arr1.size(); i++){
        cout << arr1.at(i) << endl;
    }
    cout << endl;
    cout << arr1.capacity();
    return 0;
    /*cout << endl;
    cout << arr1.capacity() << endl;
    arr1.expand(3);
    cout << arr1.capacity() << endl;
    arr1.insert(2, 5);
    for(unsigned int i = 0; i < arr1.size(); i++){
        cout << arr1.at(i);
    }
    cout << endl;
    arr1.assign(3, 6);
    for(unsigned int i = 0; i < arr1.size(); i++){
        cout << arr1.at(i);
    }*/
    cout << endl;
    arr1.push_back(12);
    for(unsigned int i = 0; i < arr1.size(); i++){
        cout << arr1.at(i) << endl;
    }
    cout << endl;
    cout << arr1.capacity();
    return 0;
}