#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include "frac.cc"

using namespace std;


template<typename T>
int buildHeap (vector<T> &V, int left, int right){
    if(right - left + 1 > V.size() || left > right){
        return -1;
    }
    if(left == right){
        return 1;
    }
    int child;
    int h;
    if(left == 0){
        int total = right - left + 1;
        for(int i = total/2; i > 0; --i){
            h = i + (left - 1);
            T tmp = std::move(V.at(h));
            for( ; h * 2 <= total; h = child )
            {
                child = h * 2;
                if(child > V.size() - 1 || child + 1 >= V.size()){
                    break;
                }
                if( child != total && V.at(child + 1) > V.at(child) )
                    ++child;
                if( V.at(child) > tmp )
                    V.at(h) = std::move( V.at(child) );
                else
                {
                    break;
                }
            }
            V.at(h) = move(tmp);
        }
    }
    else{
    //int h;
    int total = right - left + 1;
    int l = 0, r = total;
    l = total / 2;
    while (l)
    {
        --l;
        int i,j;
        T x;
        i = l;
        j = 2*i+1;
        x = V.at(i);
        while (j < total)
        {
            if ( j < total - 1)
                if ( V.at(j) < V.at(j + 1))
                    ++j;
             if (x > V.at(j) - 1)
                break;
            V.at(i) = V.at(j);
            i = j;
            j = 2*i + 1; // sift
            }
        V.at(i) = x;
    }
        /*for(int i = total/2; i > 0; --i)
        {
            cout << "total is: " << total << endl;
            h = i + (left - 1);
            cout << "h is: " << h << endl;
            T tmp = move(V.at(h));
            for( ; h * 2 <= total; h = child)
            {
                child = (h * 2);
                cout << "h * 2: " << h * 2 << endl;
                cout << "total is: " << total << endl;
                cout << "hole is " << h << "Hole value: " << V.at(h) << " " << "child is " << child << "Child value: " << V.at(child) << endl;
                
                if(child != total && V.at(child + 1) > V.at(child))
                {
                    cout << "child incremented" << endl;
                    ++child;
                }
                if(V.at(child) > tmp)
                {
                    cout << "child moved to hole" << endl;
                    V.at(h) = move(V.at(child) );
                }
                else {
                    cout << "break" << endl;
                    break;
                }
            }
            cout << "tmp moved to hole" << endl;
            V.at(h) = move(tmp);
        }*/
    }
    //sort(V.begin() + left, V.begin() + right);
    //reverse(V.begin() + left, V.begin() + right);
    for(int j = 0; j < V.size(); j++){
        if(j == left){
            cout << "[ " << V.at(left) << " ";
        }
        else if(j == right){
            cout << V.at(right) << " " << "] ";
        }
        else{
            cout << V.at(j) << " ";
        }
    }
    cout << endl;
    return 1;
}

template<typename T>
void printHeap (vector<T> &V, int left, int right){
    int size = 2;
    //cout << "right is " << right << endl;
    if(left > right){
        //cout << "left > right" << endl;
        return;
    }
    if(left == right){
        //cout << "left == right" << endl;
        cout << left << ": " << V.at(left);
        cout << endl;
        return;
    }
    cout << left << ": " << V.at(left);
    cout << endl;
    left++;
    int i = 0;
    if(left + 1 == right){
        //cout << "left + right" << endl;
        cout << left << ": " << V.at(left);
        cout << endl;
        return;
    }
    else{
    while (i != right){
        for(i = left; i < size + left; i++){
            if(i == right){
                if(i == left){
                    cout << left << ": " << V.at(left);
                    break;
                }
                else{
                    break;
                }
            }
            if(i == left){
                cout << i << ": ";
            }
            cout << V.at(i) << " ";
        }
        cout << endl;
        left = left + size;
        size = pow(size, 2);
    }
    return;
    }
}
template<typename T>
void deleteMax (vector<T> &V, int &left, int &right, T &maxItem){
    maxItem = V.at(left);
    V.erase(V.begin() + left);
    V.insert(V.begin() + right, maxItem);
    buildHeap(V, left, right - 1);
    right = right - 1;
    printHeap(V, left, right);
}
template<typename T>
int Marjory (vector<T> &V, int left, int right){
    int complete = 0;
    T maxItem;
    int size = right;
    complete = buildHeap (V, left, right);
    if(complete == -1){
        return -1;
    }
    printHeap (V, left, right);
    while(right != 0){
        //cout << "deleteMax passthrough" << endl;
        deleteMax(V, left, right, maxItem);
    }
    for(int j = 0; j < V.size(); j++){
        if(j == left){
            cout << "[ " << V.at(left) << " ";
        }
        else if(j == size){
            cout << V.at(size) << " " << "] ";
        }
        else{
            cout << V.at(j) << " ";
        }
    }
    cout << endl;
    return 1;
}
template<typename T>
int Marjory (vector<T> &V){
    int left = 0;
    int right = V.size() - 1;
    int complete = 0;
    int size = right;
    T maxItem;
    complete = buildHeap (V, left, right);
    if(complete == -1){
        return -1;
    }
    printHeap (V, left, right);
    while(right >= 0){
        deleteMax(V, left, right, maxItem);
    }
    for(int j = 0; j < V.size(); j++){
        if(j == left){
            cout << "[ " << V.at(left) << " ";
        }
        else if(j == size){
            cout << V.at(size) << " " << "] ";
        }
        else{
            cout << V.at(j) << " ";
        }
    }
    cout << endl;
    return 1;
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
    vector<int> integer;
    vector<double> doubles;
    vector<Fraction> Fractions;
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
        cout << "Vector Type: ";
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
    char bounds = 'n';
    cout << "Would you like to set bounds?(y or n): ";
    cin >> bounds;
    cout << endl;
    if(bounds == 'y'){
        int left;
        int right;
        cout << "Enter left bound: ";
        cin >> left;
        cout << endl;
        cout << "Enter right bound: ";
        cin >> right;
        cout << endl;
        if(type == 'I' || type == 'i'){
            Marjory(integer, left, right);
            cout << endl;
        }
        if(type == 'd' || type == 'D'){
            Marjory(doubles, left, right);
            cout << endl;
        }
        if(type == 'f' || type == 'F'){
            Marjory(Fractions, left, right);
            cout << endl;
        }
    }
    else{
        if(type == 'I' || type == 'i'){
            Marjory(integer);
            cout << endl;
        }
        if(type == 'd' || type == 'D'){
            Marjory(doubles);
            cout << endl;
        }
        if(type == 'f' || type == 'F'){
            Marjory(Fractions);
            cout << endl;
        }
    }
    
    
    return 0;
}