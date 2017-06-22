#include <iostream>
#include <algorithm>

using namespace std;

double mean(const double array[], int arraySize);
void remove(double array[], int arraySize, int index);
void display(const double array[], int arraySize);

int main (){
    int arraySize = 10;
    double arr[arraySize];
    double meanSum = 0.0;
    int removeNum;
    cout << "Enter 10 values:" << endl;
    for(int i = 0; i < arraySize; i++){
        cin >> arr[i];
    }
    cout << endl;
    meanSum = mean(arr, arraySize);
    cout << "Mean: " << meanSum << endl;
    cout << endl;
    cout << "Enter index of value to be removed: ";
    cin >> removeNum;
    cout << endl;
    cout << "Before removing value: ";
    display(arr, arraySize);
    cout << endl;
    remove(arr, arraySize, removeNum);
    cout << "After removing value: ";
    display(arr, arraySize - 1);
    cout << endl;
    
    return 0;
}

double mean(const double array[], int arraySize){
    double sum = 0.0;
    double mean = 0.0;
    for(int i = 0; i < arraySize; i++){
        sum += array[i];
    }
    mean = sum / arraySize;
    return mean;
}

void remove(double array[], int arraySize, int index){
    for(int i = index; i < arraySize - 1; i++){
        swap(array[i], array[(i + 1)]);
    }
    
    return;
}

void display(const double array[], int arraySize){
        for(int i = 0; i < arraySize - 1; i++){
            cout << array[i] << ", ";
        }
        cout << array[arraySize - 1];
    return;
}