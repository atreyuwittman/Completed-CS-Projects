#include <iostream>
#include <cmath>
using namespace std;

int main() {

double x1 = 0.0;
double y1 = 0.0;
double x2 = 0.0;
double y2 = 0.0;
double distance = 0.0;
double xdiff = 0.0;
double ydiff = 0.0;


cout << "Enter first x value: ";
cin >> x1;
cout << "Enter first y value: ";
cin >> y1;
cout << "Enter second x value: ";
cin >> x2;
cout << "Enter second y value: ";
cin >> y2;
xdiff = pow(x2-x1, 2.0);
ydiff = pow(y2-y1, 2.0);

distance = sqrt(xdiff + ydiff);
cout << "The distance between the two points is: " << distance << endl;

return 0;

}

