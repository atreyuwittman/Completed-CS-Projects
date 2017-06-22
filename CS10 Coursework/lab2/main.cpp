#include <iostream>
using namespace std;

int main() {
    
    string userAbbr = "";
    
    cout << "Input an abbreviation: ";
    cin >> userAbbr;
    cout << endl;
    
    if (userAbbr == "BFF"){
        cout << "best friends forever" << endl;
    }
    else if (userAbbr == "bff"){
        cout << "best friends forever" << endl;
    }
    else if (userAbbr == "IMHO"){
        cout << "in my humble opinion" << endl;
    }
    else if (userAbbr == "imho"){
        cout << "in my humble opinion" << endl;
    }
    else if (userAbbr == "TMI"){
        cout << "too much information" << endl;
    }
    else if (userAbbr == "lol"){
        cout << "laughing out loud" << endl;
    }
    else if (userAbbr == "LOL"){
        cout << "laughing out loud" << endl;
    }
    else if (userAbbr == "IDK"){
        cout << "I don't know" << endl;
    }
     else if (userAbbr == "idk"){
        cout << "I don't know" << endl;
     }
    else {
        cout << "Unknown" << endl;
        
    }
    
    
    return 0;
    
}