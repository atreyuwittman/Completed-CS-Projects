#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int WINNING_SCORE = 100;


//FIXME (1): Implement the printIntro function
void printIntro(){
    cout << "Welcome to the dice game Pig!" << endl;
    cout << "The objective is to be first to score 100 points." << endl;
    cout << endl;
    
    
    
}
//FIXME (4, 5, 6): Implement the humanTurn function
int humanTurn(string name, int score){
      
       char a = 'y';
       int preScore = score;
    while (a != 'n'){
    cout << endl;
    cout << name << endl;  
    
    int num = 0;
    num = ((rand() % 6) + 1);
    if (num == 1){
        cout << "You rolled a " << num << " (PIG!)" << endl;
        cout << "Your turn is over" << endl;
        cout << "Your score: " << preScore << endl;
        
       return preScore; 
        a = 'n';
    }
    else {
    cout << "You rolled a " << num << endl;
    
    score += num;
    cout << "Your score: " << score << endl;
    if (score >= 100){
        return score;
    }
     cout << "Do you want to roll again? (y/n): ";
    cin >> a;
    }
    
    
   

    
    
    } return score;
    
}
int main() {
    srand(4444);

    // setup and initialize variables
    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name;
    string player2name;

    printIntro();

    // FIXME (2): get names of players
    cout << "Player 1 - Enter your name: ";
    getline(cin, player1name);
    cout << endl;
    cout << "Player 2 - Enter your name: ";
    getline(cin, player2name);

    //play game
    while (player1score < WINNING_SCORE && player2score < WINNING_SCORE) {

        //player 1's turn or player 2's turn
        if (turn == PLAYER1) {
            player1score = humanTurn(player1name, player1score);
        }
        else {
            player2score = humanTurn(player2name, player2score);
        }
        //FIXME (3): switch whose turn it is
        if (turn == PLAYER1) {
            turn = PLAYER2;
        }
        else {
            turn = PLAYER1;
        } 
     
    }
    // FIXME (7): Output who won the game.
   if (player1score >= WINNING_SCORE) {
    cout << player1name << endl;
     cout << "Your score: " << player1score << endl;
     cout << endl;
    cout << player1name << " wins!";  
   }   
    if (player2score >= WINNING_SCORE) {  
       cout << player2name << endl;
        cout << "Your score: " << player2score << endl;
        cout << endl;
        cout << player2name << " wins!";
     }
    return 0;
}