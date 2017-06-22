#include <iostream>
using namespace std;

int main() {
   
    char userChar;
   int userNum = 0;
   
   cout << "Enter a character: ";
   cin >> userChar;
   cout << "Enter number of rows: ";
   cin >> userNum;
   cout << endl;
   for (int i = userNum; i >= 1;i--){
      for (int x = userNum; x >= i; x--) {
         cout << userChar << " ";
      }
      cout << endl;
   }
   
   return 0;
}