#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
    int stars = 1;
    int trunkHeight = 0;
    int trunkWidth = 0;
    int leaveWidth = 0;
    cout << "Enter trunk height: ";
    cin >> trunkHeight;
    cout << "Enter trunk width: ";
    cin >> trunkWidth;
     while ((trunkWidth % 2) == 0) {
   cout << "Please enter an odd number for the width: ";
   cin >> trunkWidth;
   trunkWidth = trunkWidth;
     }
  cout << "Enter leaves width: ";
   cin >> leaveWidth;

   for (int line = leaveWidth; line > 0 ;  line--)
     {
         
         for (int t = (line - 1); t > 0; t--)
         cout <<" ";
         
         for (int i = 0; i < stars; i++)
         cout <<"*";
         
         stars += 2;
         
         cout <<"\n";
         
         }
    
    	for( int i = 0; i < trunkHeight; ++i ) {
		for( int j = 0; j < ( leaveWidth - ( trunkWidth - ( trunkWidth / 2 ) ) ); ++j )
			std::cout << " ";

		for( int k = 0; k < trunkWidth; ++k )
			std::cout << "*";

		std::cout << '\n';
	}
    return 0;
}