#include "IntVector.h"
#include <stdexcept>
using namespace std;

IntVector::IntVector(){
    data = 0;
    sz = 0;
    cap = 0;
}
IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[size];
    for(unsigned int i = 0; i < cap; i++){
        data[i] = value;
    }
}
IntVector::~IntVector(){
    delete [] data;
}
unsigned IntVector::size() const{
    return sz;
}
unsigned IntVector::capacity() const{
    return cap;
}
bool IntVector::empty() const{
    if(sz == 0){
        return true;
    }
    return false;
}
const int & IntVector::at(unsigned index) const{
    if(index < sz){
    return data[index];
    }
    else{
        throw out_of_range("IntVector::at_range_check");
    }
}
const int & IntVector::front() const{
    return data[0];
}
const int & IntVector::back() const{
    return data[sz - 1];
}
void IntVector::insert(unsigned index, int value){
    if(index > sz){
        throw out_of_range("IntVector::insert_range_check");
    }
    else{
        if(sz + 1 > cap){
            if(sz > cap * 2){
                expand(sz - cap);
            }
            else{
                expand();
            }
        }
        for(unsigned int i = sz - 1; i > index; i--){
            data[i] = data[i + 1];
        }
        data[index] = value;
    }
}
void IntVector::erase(unsigned index){
    if(index >= sz){
        throw out_of_range("IntVector::erase_range_check");
    }
    for(unsigned int i = index; i < sz; i++){
        data[i] = data[i + 1];
    }
    sz = sz - 1;
    return;
}
int & IntVector::at(unsigned index){
    if(index < sz){
    return data[index];
    }
    else{
        throw out_of_range("IntVector::at_range_check");
    }
}
void IntVector::reserve(unsigned n){
    if(n > cap){
            if(n > cap * 2){
                expand(n - cap);
            }
            else{
                expand();
            }
        }
}
void IntVector::resize(unsigned size, int value){
    if(size <= sz){
        sz = size;
        return;
    }
    while(size > cap){
            if(size > cap * 2){
                expand(size - cap);
            }
            else{
                expand();
            }
        }
    if(size > sz){
        for(unsigned int i = sz; i < size; i++){
            data[i] = value;
        } 
    }
}
void IntVector::clear(){
   sz = 0; 
}
void IntVector::pop_back(){
    sz = sz - 1;
}
void IntVector::push_back(int value){
    if(sz >= cap){
        expand();
    }
    sz++;
    data[sz - 1] = value;
    
}
void IntVector::assign(unsigned n, int value){
    sz = n;
    if(sz > cap){
            if(sz > cap * 2){
                expand(sz - cap);
            }
            else{
                expand();
            }
        }
    for(unsigned int i = 0; i < sz; i++){
        data[i] = value;
    }
}
int & IntVector::back(){
    return data[sz - 1];
}
int & IntVector::front(){
    return data[0];
}
void IntVector::expand(){
    if(cap == 0){
        cap = 1;
        delete [] data;
        data = new int[cap];
    }
    else{
    int newCap = 2 * cap;
    int *temp = new int[newCap];
    for(unsigned int i = 0; i < sz; i++){
        int tamp = data[i];
        temp[i] = tamp;
    }
    delete [] data;
    data = temp;
    cap = newCap;
    }
}
void IntVector::expand(unsigned n){
   if(cap == 0){
       cap = n;
       delete [] data;
       data = new int[n];
   }
   else{
   int newCap = n + cap;
    int *temp = new int[newCap];
    for(unsigned int i = 0; i < sz; i++){
        int tamp = data[i];
        temp[i] = tamp;
    }
    delete [] data;
    data = temp;
    cap = newCap;
   }
}
