#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

double FibLoopCount ( int n, int & totalAdds, int & totalCalls){
    double x = 0;
    double y = 1;
    double next = 0;
    double count = 0;
    totalCalls++;
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
        totalAdds++;
    }
    return next;
}
void FFRC2( int n, double &(Fn_1), double & Fn, int & totalAdds, int & totalCalls ){
    totalCalls++;
    if(n == 1){
        Fn_1 = 0;
        Fn = 1;
        return;
    }
    else{ 
        FFRC2( n - 1, Fn_1, Fn, totalAdds, totalCalls);
    }
    n = Fn + Fn_1;
    Fn_1 = Fn;
    Fn = n;
    totalAdds++;
    return;
}
double FastFibRecCount ( int n, int & totalAdds, int & totalCalls ){
    double twoBack = n - 2;
    double oneBack = n - 1;
     if(n == 0){
         totalCalls++;
        return 0;
    }
    if(n == 1){
        totalCalls++;
        return 1;
    }
    FFRC2(n - 1, twoBack, oneBack, totalAdds, totalCalls);
    return (oneBack + twoBack);
}

int main() {
    ofstream outFS;
    string fileName = "test2.csv";
    int MAX_N = 30;
    int MAX_CALLS = 100000;
    int totalAdds1 = 0;
    int totalAdds2 = 0;
    int totalCalls1 = 0;
    int totalCalls2 = 0;
    outFS.open(fileName.c_str());
            if (!outFS.is_open()) {
                cout << "Could not open file " << fileName << "." << endl;
                return 1; 
                }
    for(int i = 0; i < MAX_N + 1; i++){
    if(FibLoopCount(i, totalAdds1, totalCalls1) == FastFibRecCount(i, totalAdds2, totalCalls2)){
        if(totalCalls1 > MAX_CALLS || totalCalls2 > MAX_CALLS){
            outFS.close();
            return 0;
        }
        outFS << "1. Parameter Value:" << i << endl;
        outFS << "2. Times the Iteration Program Added: " << totalAdds1 << endl;
        outFS << "3. Times the Iteration Program Was Called: " << totalCalls1 << endl;
        outFS << "4. Times the Recursive Program Added: " << totalAdds2 << endl;
        outFS << "5. Times the Recursive Program Was Called: " << totalCalls2 << endl;
        totalAdds1 = 0;
        totalAdds2 = 0;S
        totalCalls1 = 0;
        totalCalls2 = 0;
        }
        else{
        outFS << FibLoopCount(i, totalAdds1, totalCalls1) << " is not the same answer as " << FastFibRecCount(i, totalAdds2, totalCalls2);
        return 0;
        }
    }
    outFS.close();
    return 0;
    
}