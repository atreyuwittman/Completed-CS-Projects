#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cmath>

using namespace std;

int closest2key ( double key, double num[ ], int n, int & numCompares ){
    int num1 = 0;
    int numLoc = 0;
    int num2 = 0;
    numCompares = 0;
    if(key < 1){
        return -1;
    }
    for(int i = 1; i < n + 1; i++){
        numCompares++;
        if(key == num[i]){
            return i;
        }
        if(i == 1){
            num1 = abs(key - num[i]);
            numLoc = i;
        }
        else {
            num2 = abs(key - num[i]);
            if(num1 > num2){
                num1 = num2;
                numLoc = i;
            }
        }
    }
    return numLoc;
}
int closestBinary ( double key, double num[ ], int n, int & numCompares ){
    int low = 1;
    int high = n + 1;
    int num1 = abs(key - num[1]);
    int num2 = 0;
    int numLoc = 0;
    numCompares = 0;
    if(key < 1){
        return -1;
    }
    while( low <= high )
    {
        int mid = ( low + high ) / 2;
        if(key == num[mid]){
            numCompares++;
            return mid;
        }
        else if(num[ mid ] < key){
            low = mid + 1;
            numCompares++;
        }
        else if( num[ mid ] > key ){
            high = mid - 1;
            numCompares++;
            }   
        num2 = abs(key - num[mid]);
        numCompares++;
        if(num1 > num2){
            num1 = num2;
            numLoc = mid;
            }
    }
        return numLoc;
}
int giantStepper ( double key, double sorted[ ], int size, int & numCompares ){
    numCompares = 0;
    int steps = sqrt(size);
    int num1 = abs(key - sorted[1]);
    int num2 = 0;
    int numLoc = 0;
    if(key < 1){
        return -1;
    }
    for(int i = 1; i < size + 1; i = i + steps){
        numCompares++;
        if(key == sorted[i]){
            return i;
        }
        else if(sorted[i] > key){
            for(int j = i; j > i - steps; j--){
                numCompares++;
                if(key == sorted[j]){
                    return j;
                }
                else{
                    num2 = abs(key - sorted[j]);
                    if(num1 > num2){
                        num1 = num2;
                        numLoc = j;
                    }
                }
            }
        }
        if(i + steps > size + 1){
            steps = abs((i + steps) - (size + 1));
        }
    }
    return numLoc;
}

int main(int argc, char* argv[]){
    ifstream inFS;
    int size = 0;
    double value = 0.0;
    double *num;
    double *alt;
    double *sorted;
    int key = 0;
    int linear = 0;
    int binary = 0;
    int quadratic = 0;
    int numCompares = 0;
    char keepGoing = 'y';
    string fileName = "";
    if(argc == 2){
        fileName = argv[1];
    }
    if(fileName == ""){
        cout << "Size of the array: ";
        cin >> size;
        num = new double[size + 1];
        cout << endl;
        for(int j = 1; keepGoing == 'y' && j < size + 1; j++){
            cout << "Enter Number: ";
            cin >> value;
            num[j] = value;
            cout << endl;
            if(j + 1 != size + 1){
            cout << "Keep Going? (Enter y or n): ";
            cin >> keepGoing;
            cout << endl;
            }
            if(keepGoing == 'n'){
                alt = new double[j + 1];
                for(int m = 1; m < j + 1; m++){
                    alt[m] = num[m];
                }
                num = alt;
                size = j;
                delete [] alt;
            }
        }
    }
    else {
       inFS.open(fileName.c_str());
        inFS >> size;
        num = new double[size + 1];
        for(int k = 1; k < size + 1; k++){
            inFS >> value;
            num[k] = value;
        }
    }
    sorted = new double[size];
    for(int c = 1; c < size + 1; c++){
        sorted[c] = num[c];
    }
    sort(sorted, sorted + size + 1);
    cout << "Enter value to search for: ";
    cin >> key;
    linear = closest2key (key, num, size, numCompares);
    cout << "Linear Search:: Index: " << linear << ", Closest Value: " << num[linear] <<", Number of Comparisons: " << numCompares << endl;
    binary = closestBinary (key, sorted, size, numCompares);
    cout << "Binary Search:: Index: " << binary << ", Closest Value: " << sorted[binary] << ", Number of Comparisons: " << numCompares << endl;
    quadratic = giantStepper(key, sorted, size, numCompares);
    cout << "Quadratic Search:: Index: " << quadratic << ", Closest Value: " << sorted[quadratic] << ", Number of Comparisons: " << numCompares << endl;
    
    
    return 0;
}