#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include "frac.cc"

using namespace std;


template<typename T>
void print_list (list<T> in_list){
    for(typename list<T>::iterator iter = in_list.begin(); iter != in_list.end(); iter++){
            cout << *iter << ' ';
    }
}

template<typename T>
int split_list (list<T> & in_list, list<T> & reject_list, int k){
    int numDeletes = 0;
    int keyIters = 1;
    if(k == 0){
        return numDeletes;
    }
    if(k == 1){
        for(typename list<T>::iterator iter = in_list.begin(); iter != in_list.end(); iter++){
                reject_list.push_back(*iter);
                iter = in_list.erase(iter);
                iter--;
                numDeletes++;
            }
            return numDeletes;
    }
    else if(k == 2){
        for(typename list<T>::iterator iter = in_list.begin(); iter != in_list.end(); ++iter){
            if(keyIters % k == 0){
                reject_list.push_back(*iter);
                iter = in_list.erase(iter);
                numDeletes++;
                iter--;
                keyIters = 0;
            }
            keyIters++;
        }
        return numDeletes;
    }
    else{
    int totalIters = in_list.size();
        for(typename list<T>::iterator iter = in_list.begin(); iter != in_list.end(); ++iter){
            if(totalIters > 0){
            if(keyIters % k == 0){
                reject_list.push_back(*iter);
                iter = in_list.erase(iter);
                numDeletes++;
                keyIters = 1;
            }
            totalIters--;
            keyIters++;
            }
            else{
            return numDeletes;
            }
        }
    }
}
template<typename T, typename iterator>
void print_sort (list<T> in_list, iterator P, iterator P1, iterator P2, int blockSize){
    int iters = 0;
    for(typename list<T>::iterator iter = in_list.begin(); iter != in_list.end(); iter++){
            if(iter == P){
                cout << "[ ";
            }
            if(iter == P1){
                cout << ") ";
            }
            if(iter == P2){
                cout << ") ";
            }
            cout << *iter << ' ';
            if(iters == blockSize){
                cout << "] ";
            }
    }
    cout << endl;
}

template<typename T, typename iterator>
iterator & merge(list<T> & myList, iterator & L1, int Lblock, iterator & L2, int Rblock){
    typename list<T>::iterator L = L1;
    typename list<T>::iterator LL = L2;
    typename list<T>::iterator L3 = LL;
    advance(L3, Rblock);
    for(typename list<T>::iterator iter = L1; iter != LL && L2 != L3; ++iter){
        cout << endl << *L << " " << *L1 << " " << *L2 << endl;
    //print_sort(myList, L, L1, L2, Lblock + Rblock);
    print_list(myList);
    if(*L1 <= *L2){
        cout << "Not copied" << endl;
        L1++;
    }
    else{
        if(L1 != L){
            cout << "copied" << endl;
            T cpy = *L2;
            L2 = myList.erase(L2);
            L1 = myList.insert(L1, cpy);
        }
        else{
            cout << "copied2" << endl;
            T cpy = *L2;
            L2 = myList.erase(L2);
            L = myList.insert(L1, cpy);
            }
        }
    }
    L1 = L;
    return L1;
}
template<typename T, typename iterator>
void mergesort(list<T> & myList, iterator & L, int blockSize){
    if(blockSize < 2){
        return;
    }
    int Lblock = blockSize/2;
    int Rblock = blockSize - Lblock;
    typename list<T>::iterator L1 = L;
    typename list<T>::iterator L2 = L;
    advance(L2, Rblock);
    mergesort (myList, L1, Lblock);
    mergesort (myList, L2, Rblock);
    merge(myList, L1, Lblock, L2, Rblock);
    
}



int main(int argc, char* argv[]){
    ifstream inFS;
    stringstream completeLine;
    char type = 'a';
    char filledList = 'n';
    char noMore = 'n';
    int num = 0;
    int dem = 1;
    Fraction Fract(num, dem);
    list <int> integer;
    list <double> doubles;
    list <Fraction> Fractions;
    int linear = 0;
    int value = 0;
    double val2 = 0.0;
    int numCompares = 0;
    string temp = "";
    char keepGoing = 'y';
    string fileName = "";
    if(argc == 2){
        fileName = argv[1];
    }
    if(fileName == ""){
        while(noMore == 'n'){
        cout << "List Type: ";
        cin >> type;
        cout << endl;
        while(filledList == 'n'){
            if(type != 'I' && type != 'i' && type != 'D' && type != 'd' && type != 'F' && type != 'f'){
            cout << "Not a Valid Type, Please try again: ";
            cin >> type;
            cout << endl;
            }
            else{
            for(int i = 0; keepGoing == 'y'; i++){
                if(type == 'I' || type == 'i'){
                    cout << "Enter Value: ";
                    cin >> value;
                    integer.push_back(value);
                    cout << endl;
                    completeLine >> value;
                    cout << "Keep Going? (Enter y or n): ";
                    cin >> keepGoing;
                    cout << endl;
                    }
                if(type == 'D' || type == 'd'){
                    cout << "Enter Value: ";
                    cin >> val2;
                    doubles.push_back(val2);
                    cout << endl;
                    completeLine >> val2;
                    cout << "Keep Going? (Enter y or n): ";
                    cin >> keepGoing;
                    cout << endl;
            
                }
                if(type == 'F' || type == 'f'){
                    cout << "Numerator: ";
                    cin >> num;
                    cout << endl;
                    cout << "Denominator: ";
                    cin >> dem;
                    cout << endl;
                    while(dem == 0){
                        cout << "Error: Denominator cannot be zero. Try again: ";
                        cin >> dem;
                        cout << endl;
                    }
                    completeLine >> num >> dem;
                    Fractions.push_back(Fraction(num, dem));
                    cout << endl;
                    cout << "Keep Going? (Enter y or n): ";
                    cin >> keepGoing;
                    cout << endl;
                    }
                }
                filledList == 'y';
                }
            }
            cout << "Do you want to create another list? (y or n): ";
            cin >> noMore;
            cout << endl;
        }
    }
    else {
       inFS.open(fileName.c_str());
        while(!inFS.eof()){
        getline(inFS, temp, '\n');
        completeLine << temp;
        completeLine >> type;
        if(type == 'I' || type == 'i'){
            while(completeLine >> value){
                integer.push_back(value);
            }
        }
        if(type == 'd' || type == 'D'){
            while(completeLine >> val2){
                doubles.push_back(val2);
            }
        }
        if(type == 'f' || type == 'F'){
            while(completeLine >> num >> dem){
                Fractions.push_back(Fraction(num, dem));
            }
        }
    }
    }
        if(type == 'I' || type == 'i'){
            print_list (integer);
            cout << endl;
        }
        if(type == 'd' || type == 'D'){
            print_list (doubles);
            cout << endl;
        }
        if(type == 'f' || type == 'F'){
            print_list (Fractions);
            cout << endl;
        }
        
        /*if(type == 'I' || type == 'i'){
            integer.sort();
            print_list (integer);
            cout << endl;
        }
        if(type == 'd' || type == 'D'){
            doubles.sort();
            print_list (doubles);
            cout << endl;
        }
        if(type == 'f' || type == 'F'){
            Fractions.sort();
            print_list (Fractions);
            cout << endl;
        }*/
        int nthTerm;
        cout << "Enter a number for removing every nth element: ";
        cin >> nthTerm;
        if(type == 'I' || type == 'i'){
            list <int> reject_list1;
            split_list(integer, reject_list1, nthTerm);
            print_list (integer);
            cout << endl;
            print_list (reject_list1);
            cout << endl;
        }
        if(type == 'd' || type == 'D'){
            list <double> reject_list2;
            split_list(doubles, reject_list2, nthTerm);
            print_list (doubles);
            cout << endl;
            print_list (reject_list2);
            cout << endl;
        }
        if(type == 'f' || type == 'F'){
            list <Fraction> reject_list3;
            split_list(Fractions, reject_list3, nthTerm);
            print_list (Fractions);
            cout << endl;
            print_list (reject_list3);
            cout << endl;
        }
        list<int>::iterator intIter = integer.begin();
        mergesort(integer, intIter, integer.size());
        print_list(integer);

    
    
    return 0;
}