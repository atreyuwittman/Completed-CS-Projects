#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "frac.cc"

using namespace std;

template <typename Comparable>
int closest2key ( Comparable key, const vector <Comparable> & A, int & numCompares ){
    Comparable num1 = 0;
    int numLoc = 0;
    Comparable num2 = 0;
    Comparable dist = 0;
    numCompares = 0;
    cout << "=====" << endl;
    if(key < 0){
        return -1;
    }
        for(int i = 0; i < A.size(); i++){
        numCompares++;
        if(key == A.at(i)){
            cout << "A[" << i << "] = " << A.at(i) << ", Key Distance = " << dist << endl;
            cout << "=====" << endl;
            return i;
        }
        if(i == 0){
            num1 = key - A.at(i);
            if( num1  < 0){
                num1 = num1 * -1;
            }
            numLoc = i;
        }
        else {
            num2 = key - A.at(i);
            if( num2  < 0){
                num2 = num2 * -1;
            }
            if(num1 > num2){
                num1 = num2;
                numLoc = i;
            }
        }
        dist = key - A.at(i);
        if( dist  < 0){
                dist = dist * -1;
            }
        cout << "A[" << i << "] = " << A.at(i) << ", Key Distance = " << dist << endl;
        }
    cout << "=====" << endl;
    return numLoc;
}

int main(int argc, char* argv[]){
    ifstream inFS;
    char type = 'a';
    int num = 0;
    int dem = 1;
    Fraction Fract(num, dem);
    vector <int> integer;
    vector <double> doubles;
    vector <Fraction> Fractions;
    int linear = 0;
    int value = 0;
    double val2 = 0.0;
    int numCompares = 0;
    char keepGoing = 'y';
    string fileName = "";
    if(argc == 2){
        fileName = argv[1];
    }
    if(fileName == ""){
        cout << "Vector Type: ";
        cin >> type;
        cout << endl;
        if(type == 'I' || type == 'i' || type == 'D' || type == 'd' ||type == 'F' || type == 'f'){
            for(int i = 0; keepGoing == 'y'; i++){
                if(type == 'I' || type == 'i'){
                    cout << "Enter Value: ";
                    cin >> value;
                    integer.push_back(value);
                    cout << endl;
                    cout << "Keep Going? (Enter y or n): ";
                    cin >> keepGoing;
                    cout << endl;
                    }
                if(type == 'D' || type == 'd'){
                    cout << "Enter Value: ";
                    cin >> val2;
                    doubles.push_back(val2);
                    cout << endl;
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
                    Fractions.push_back(Fraction(num, dem));
                    cout << endl;
                    cout << "Keep Going? (Enter y or n): ";
                    cin >> keepGoing;
                    cout << endl;
                }
            }
        }
        else{
            cout << "File type not recognized, program closing.";
            return 0;
        }
    }
    else {
       inFS.open(fileName.c_str());
        inFS >> type;
        if(type == 'I' || type == 'i')
            for(int k = 0; (!inFS.eof()); k++){
                inFS >> value;
                integer.push_back(value);
        }
        if(type == 'd' || type == 'D')
            for(int k = 0; (!inFS.eof()); k++){
                inFS >> val2;
                doubles.push_back(val2);
        }
        if(type == 'f' || type == 'F')
            for(int k = 0; (!inFS.eof()); k++){
                inFS >> num >> dem;
                Fractions.push_back(Fraction(num, dem));
        }
        
    }
    //sort(sorted, sorted + size + 1);
    int key = 0;
    double key2 = 0;
    if(type == 'I' || type == 'i'){
        cout << "Enter value to search for: ";
        cin >> key;
        linear = closest2key (key, integer, numCompares);
        cout << "Linear Search:: Index: " << linear << ", Closest Value: " << integer.at(linear) <<", Number of Comparisons: " << numCompares << endl;
    }
    if(type == 'd' || type == 'D'){
        cout << "Enter value to search for: ";
        cin >> key2;
        linear = closest2key (key2, doubles, numCompares);
        cout << "Linear Search:: Index: " << linear << ", Closest Value: " << doubles.at(linear) <<", Number of Comparisons: " << numCompares << endl;
    }
    if(type == 'f' || type == 'F'){
        cout << "Enter Numerator (space) Denominator to search for: ";
        cin >> num >> dem;
        Fraction key3(num, dem);
        linear = closest2key (key3, Fractions, numCompares);
        cout << "Linear Search:: Index: " << linear << ", Closest Value: " << Fractions.at(linear) <<", Number of Comparisons: " << numCompares << endl;
    }
    
    
    return 0;
}
