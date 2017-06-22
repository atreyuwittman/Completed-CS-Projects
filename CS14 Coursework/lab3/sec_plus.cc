#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double function1(double x){
    double y = pow(x, 2) - 2;
    return y;
}
double function2(double x){
    double y = pow(x, 5) - pow(x, 3) - 1;
    return y;
}
double function3(double x){
    double y = ((2 * pow(x, 3)) - ( 4 * pow(x, 2)) + (3 * x));
    return y;
}
double sec_plus (double (*f) (double x), double a, double b, double eps, int & numCompares){
    double mid = 0;
    char prevA = 'n';
    char prevB = 'n';
    double Fa = f(a);
    double Fb = f(b);
    cout << setprecision(16);
    cout << setw(22) << "a" << setw(22) << "Fa" << setw(22) << "b" << setw(22) << "Fb" << setw(22) << "midpoint" << setw(22) << "Fm" << setw(22) << "b-a" << endl;
    numCompares = 0;
    while( a <= b && b-a > eps){
        mid = ((Fb * a) - (Fa * b)) / (Fb - Fa);
        double Fm = f(mid);
        cout << setw(22) << a << setw(22) << Fa << setw(22) << b << setw(22) << Fb << setw(22) << mid << setw(22) << Fm << setw(22) << b - a << endl;
        numCompares++;
        if(Fm == 0){
            return mid;
        }
        else if(Fa * Fm >= 0){
                a = mid;
                Fa = Fm;
                prevB = 'n';
                if(prevA == 'y'){
                    Fb = Fb / 2;
                }
                prevA = 'y';
        }
        else{
                b = mid;
                Fb = Fm;
                prevA = 'n';
                if(prevB == 'y'){
                    Fa = Fa / 2;
                }
                prevB = 'y';
        }
    }
    return mid;
}


double bisect (double (*f) (double x), double a, double b, double eps, int & numCompares){
    double mid = 0;
    double Fa = 0;
    double Fb = 0;
    cout << setprecision(16);
    cout << setw(22) << "a" << setw(22) << "Fa" << setw(22) << "b" << setw(22) << "Fb" << setw(22) << "midpoint" << setw(22) << "Fm" << setw(22) << "b-a" << endl;
    numCompares = 0;
    while( a <= b && (b-a) / 2 > eps){
        mid = a + (b - a) / 2;
        double Fm = f(mid);
        Fa = f(a);
        Fb = f(b);
        cout << setw(22) << a << setw(22) << Fa << setw(22) << b << setw(22) << Fb << setw(22) << mid << setw(22) << Fm << setw(22) << b - a << endl;
        numCompares++;
        if(f(mid) == eps){
            return mid;
        }
        else if(f(a) * f(mid) >= 0){
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
    cout << "x^2 - 2:" << endl;
    double root1 = bisect (function1, a, b, eps1, numCompares);
    cout << "Bisect: The root between " << a << " and " << b << " with single precision is: " << root1 << "; Number of Comparisons: " << numCompares << endl;
    root1 = bisect (function1, a, b, eps2, numCompares);
    cout << "Bisect: The root between " << a << " and " << b << " with double precision is: " << root1 << "; Number of Comparisons: " << numCompares << endl;
    a = 1;
    b = 2;
    cout << "x^5 - x^3 - 1:" << endl;
    double root2 = bisect (function2, a, b, eps1, numCompares);
    cout << "Bisect: The root between " << a << " and " << b << " with single precision is: " << root2 << "; Number of Comparisons: " << numCompares << endl;
    root2 = bisect(function2, a, b, eps2, numCompares);
    cout << "Bisect: The root between " << a << " and " << b << " with double precision is: " << root2 << "; Number of Comparisons: " << numCompares << endl;
    a = -1;
    b = 1;
    cout << "2x^3 - 4x^2 + 3x:" << endl;
    double root5 = bisect(function3, a, b, eps1, numCompares);
    cout << "Bisect: The root between " << a << " and " << b << " with single precision is: " << root5 << "; Number of Comparisons: " << numCompares << endl;
    root5 = bisect(function3, a, b, eps2, numCompares);
    cout << "Bisect: The root between " << a << " and " << b << " with double precision is: " << root5 << "; Number of Comparisons: " << numCompares << endl;
    a = 1;
    b = 2;
    cout << "x^2 - 2:" << endl;
    double root3 = sec_plus(function1, a, b, eps1, numCompares);
    cout << "Secant: The root between " << a << " and " << b << " with single precision is: " << root3 << "; Number of Comparisons: " << numCompares << endl;
    root3 = sec_plus(function1, a, b, eps2, numCompares);
    cout << "Secant: The root between " << a << " and " << b << " with double precision is: " << root3 << "; Number of Comparisons: " << numCompares << endl;
    a = 1;
    b = 2;
    cout << "x^5 - x^3 - 1:" << endl;
    double root4 = sec_plus(function2, a, b, eps1, numCompares);
    cout << "Secant: The root between " << a << " and " << b << " with single precision is: " << root4 << "; Number of Comparisons: " << numCompares << endl;
    root4 = sec_plus(function2, a, b, eps2, numCompares);
    cout << "Secant: The root between " << a << " and " << b << " with double precision is: " << root4 << "; Number of Comparisons: " << numCompares << endl;
    a = -1;
    b = 1;
    cout << "2x^3 - 4x^2 + 3x:" << endl;
    double root6 = sec_plus(function3, a, b, eps1, numCompares);
    cout << "Secant: The root between " << a << " and " << b << " with single precision is: " << root6 << "; Number of Comparisons: " << numCompares << endl;
    root6 = sec_plus(function3, a, b, eps2, numCompares);
    cout << "Secant: The root between " << a << " and " << b << " with double precision is: " << root6 << "; Number of Comparisons: " << numCompares << endl;
    
    return 0;
}