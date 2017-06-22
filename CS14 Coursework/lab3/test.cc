#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;

int main(int argc, char* argv[]){
    Fraction fract(25, 50);
    Fraction fracted(25, 50);
    Fraction c = fract - fracted;
    cout << c.num() << endl << c.den() << endl;
    
    
    return 0;
}