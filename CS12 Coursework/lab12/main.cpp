#include <iostream>
#include <string>
using namespace std;

void flipString(string &s){
    if(s.size() == 0){
       return;
   }
   string tempStr = s.substr(0, 1);
   s = s.substr(1, s.size());
   flipString(s);
   s = s + tempStr;
    
}

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}