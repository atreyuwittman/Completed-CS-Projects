#include <iostream>
using namespace std;

// FIXME (1) Write add function stub
int add(int num1, int num2){
    int total = 0;
    total = num1 + num2;
    
    return total;
}
// FIXME (5) Write full definition of the add function

// FIXME (2) Write subtract function stub
int subtract(int num1, int num2){
    int tot = 0;
    tot = num1 - num2;
    
    return tot;
}
// FIXME (7) Write the full definition of the sub function

int main() {
   int num1 = 0;
   int num2 = 0;
   int sum = 0; //sum of numbers
   int diff = 0; //difference of numbers

   // FIXME (3) Prompt user for ints and print them
   cout << "Enter the first integer: ";
   cin >> num1;
   cout << "Enter the second integer: ";
   cin >> num2;
   cout << endl;
   cout << endl;
   // Call add function
   sum = add(num1, num2);

   // FIXME (4) Call subtract function
    diff = subtract(num1, num2);
    
    cout << "First Integer: " << num1 << endl;
    cout << "Second Integer: " << num2 << endl;
    cout << endl;

   // FIXME (6) Output result of num1 + num2
    cout << num1 << " + " << num2 << " = " << sum << endl;

   // FIXME (8) Output result of num1 - num2
    cout << num1 << " - " << num2 << " = " << diff << endl;

   return 0;
}