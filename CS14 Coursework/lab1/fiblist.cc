#include <iostream>


using namespace std;

double Fibloop(int n){
    double x = 0;
    double y = 1;
    double next = 0;
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    for(int i = 2; i < n + 1; i++){
        next = x + y;
        x = y;
        y = next;
    }
    return next;
}
double FibRec(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n > 1){
        return FibRec(n - 1) + FibRec(n - 2);
    }
}

int main() {
    int n = 0;
    cout << "Enter a Number: ";
    cin >> n;
    cout << endl;
    for(int i = 0; i < n + 1; i++){
    if(Fibloop(i) == FibRec(i)){
        cout << Fibloop(i) << " " << FibRec(i) << endl;
    }
    else{
        cout << Fibloop(i) << " is not the same answer as " << FibRec(i);
        return 0;
        }
    }
    return 0;
}