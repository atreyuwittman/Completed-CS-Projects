#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cmath>

using namespace std;

double function1(double x){
    double y = pow(x, 2) - 2;
    return y;
}
double function2(double x){
    double y = pow(x, 5) - pow(x, 3) - 1;
    return y;
}

double bisect (double (*f) (double x), double a, double b, double eps, int & numCompares){
    double mid = 0;
    while( a <= b && abs(b-a)/ 2 > eps){
        mid = a + (b - a) / 2;
        numCompares++;
        if(f(mid) == 0){
            return mid;
        }
        else if(f(a) * f(mid) > 0){
                a = mid;
        }
        else{
                b = mid;
        }
    }
    return mid;
}
int main(){
    double eps1 = 1e-6;
    double eps2 = 1e-15;
    int numCompares = 0;
    double a = 1;
    double b = 2;
    double root1 = bisect (function1, a, b, eps1, numCompares);
    cout << "x^2 - 2:" << endl;
    cout << "The root between " << a << " and " << b << " with single precision is: " << root1 << "; Number of Comparisons: " << numCompares << endl;
    root1 = bisect (function1, a, b, eps2, numCompares);
    cout << "The root between " << a << " and " << b << " with double precision is: " << root1 << "; Number of Comparisons: " << numCompares << endl;
    a = 1;
    b = 2;
    cout << "x^5 - x^3 - 1:" << endl;
    double root2 = bisect (function2, a, b, eps1, numCompares);
    cout << "The root between " << a << " and " << b << " with single precision is: " << root2 << "; Number of Comparisons: " << numCompares << endl;
    root2 = bisect (function2, a, b, eps2, numCompares);
    cout << "The root between " << a << " and " << b << " with double precision is: " << root2 << "; Number of Comparisons: " << numCompares << endl;
    
    
    
    return 0;
}