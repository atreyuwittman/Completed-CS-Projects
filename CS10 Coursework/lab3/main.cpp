#include <iostream>
#include <string>
#include <cmath>
using namespace std;

 int main(){
    string playerName1 = "";
    string playerName2 = "";
    string playerName3 = "";
    int playerYard1 = 0;
    int playerYard2 = 0;
    int playerYard3 = 0;
    
    cout << "Enter player 1's name:";
    cin >> playerName1;
    cout << endl;
    cout << "Enter player 1's yards gained:";
    cin >> playerYard1;
    cout << endl;
    cout << "Enter player 2's name:";
    cin >> playerName2;
    cout << endl;
    cout << "Enter player 2's yards gained:";
    cin >> playerYard2;
    cout << endl;
    cout << "Enter player 3's name:";
    cin >> playerName3;
    cout << endl;
    cout << "Enter player 3's yards gained:";
    cin >> playerYard3;
    cout << endl;
    cout << endl;
    
    cout << "Player 1 - " << playerName1 << ": " << playerYard1 << endl;
    cout << "Player 2 - " << playerName2 << ": " << playerYard2 << endl;
    cout << "Player 3 - " << playerName3 << ": " << playerYard3 << endl;
    
    if (playerYard1 > playerYard2 && playerYard1 > playerYard3){
        if (playerYard2 > playerYard3){
            cout << "1. " << playerName1 << ": " << playerYard1 << endl;
            cout << "2. " << playerName2 << ": " << playerYard2 << endl;
            cout << "3. " << playerName3 << ": " << playerYard3 << endl;
        }
        else {
            cout << "1. " << playerName1 << ": " << playerYard1 << endl;
            cout << "2. " << playerName3 << ": " << playerYard3 << endl;
            cout << "3. " << playerName2 << ": " << playerYard2 << endl;
        }
    }
    else if (playerYard2 > playerYard1 && playerYard2 > playerYard3){
        if (playerYard1 > playerYard3){
            cout << "1. " << playerName2 << ": " << playerYard2 << endl;
            cout << "2. " << playerName1 << ": " << playerYard1 << endl;
            cout << "3. " << playerName3 << ": " << playerYard3 << endl;
        }
        else {
            cout << "1. " << playerName2 << ": " << playerYard2 << endl;
            cout << "2. " << playerName3 << ": " << playerYard3 << endl;
            cout << "3. " << playerName1 << ": " << playerYard1 << endl;
        }
    }
    else {
        if (playerYard2 > playerYard1){
            cout << "1. " << playerName3 << ": " << playerYard3 << endl;
            cout << "2. " << playerName2 << ": " << playerYard2 << endl;
            cout << "3. " << playerName1 << ": " << playerYard1 << endl;
        }
        else {
            cout << "1. " << playerName3 << ": " << playerYard3 << endl;
            cout << "2. " << playerName1 << ": " << playerYard1 << endl;
            cout << "3. " << playerName2 << ": " << playerYard2 << endl;
        }

    }
    
    
    
    return 0;
}