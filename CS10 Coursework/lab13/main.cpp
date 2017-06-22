#include <vector>
#include <iostream>

using namespace std;

const bool CLEAR_SCREEN = true;

/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen() {
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }

    cout << endl;

    return;
}


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;

    return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {
    char ltr = 'a';
    // TODO: implement function
    for(unsigned int i = 0; i < v.size(); i++){
        v.at(i) = ltr;
        ltr = ltr + 1;
    }
    return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
    int vectorPos = 0;
    // TODO: implement function
    vectorPos = boardPosition - 'a';
    return vectorPos;
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector <char> &gameBoard, int positionIndex) {

    // TODO: implement function
    if(gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O' ){
      return true;
    }
    if(positionIndex > 8){
        return false;
    }
    return false;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector <char> &gameBoard) {

    // TODO: implement function
    int placement = 0;
    char boardPosition = ' ';
    int pos = 0;
    while (placement != 1){
    cout << "Please choose a position: ";
    cout << endl;
    cin >> boardPosition;
    if(boardPosition <= 'i'){
         pos = convertPosition(boardPosition);
        if(validPlacement(gameBoard, pos) == 1){
            placement = 1;
         }
    }
   

    }
    return pos;
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector <char> &gameBoard) {

    // TODO: implement function
    for(unsigned int i = 0; i < gameBoard.size(); i++){
        if (gameBoard.at(0) == 'X' && gameBoard.at(3) == 'X' && gameBoard.at(6) == 'X'){
           return true; 
        }
        else if (gameBoard.at(0) == 'X' && gameBoard.at(1) == 'X' && gameBoard.at(2) == 'X'){
           return true; 
        }
        else if (gameBoard.at(3) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(5) == 'X'){
          return true;  
        }
        else if (gameBoard.at(6) == 'X' && gameBoard.at(7) == 'X' && gameBoard.at(8) == 'X'){
         return true;   
        }
        else if (gameBoard.at(1) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(7) == 'X'){
           return true; 
        }
        else if (gameBoard.at(2) == 'X' && gameBoard.at(5) == 'X' && gameBoard.at(8) == 'X'){
           return true; 
        }
        else if (gameBoard.at(2) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(6) == 'X'){
           return true; 
        }
        else if (gameBoard.at(0) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(8) == 'X'){
           return true; 
        }
        else if (gameBoard.at(0) == 'O' && gameBoard.at(3) == 'O' && gameBoard.at(6) == 'O'){
            return true;
        }
        else if (gameBoard.at(0) == 'O' && gameBoard.at(1) == 'O' && gameBoard.at(2) == 'O'){
            return true;
        }
        else if (gameBoard.at(3) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(5) == 'O'){
            return true;
        }
        else if (gameBoard.at(6) == 'O' && gameBoard.at(7) == 'O' && gameBoard.at(8) == 'O'){
            return true;
        }
        else if (gameBoard.at(1) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(7) == 'O'){
            return true;
        }
        else if (gameBoard.at(2) == 'O' && gameBoard.at(5) == 'O' && gameBoard.at(8) == 'O'){
            return true;
        }
        else if (gameBoard.at(2) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(6) == 'O'){
            return true;
        }
        else if (gameBoard.at(0) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(8) == 'O'){
            return true;
        }
        
    }
    return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector <char> &gameBoard) {

    // TODO: implement function
    int n = 0;
    for(unsigned int i = 0; i < gameBoard.size(); i++){
        if(gameBoard.at(i) == 'X' || gameBoard.at(i) == 'O'){
            n++;
        }
    }
    if(n == 9){
        return true;
    }
    return false;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
    // Variables that you may find useful to utilize
    vector <char> gameBoard(9);
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'
    int place = 0;
    int curPlay = 0;
    /// TODO: Initialize board to empty state
    /// TODO: Display empty board
    initVector(gameBoard);
    drawBoard(gameBoard);
    
    /// TODO: Play until game is over
    while(boardFull(gameBoard) != 1 && gameWon(gameBoard) != 1){   
        /// TODO: Get a play
        /// TODO: Set the play on the board
        place = getPlay(gameBoard);
        if(whosTurn == PLAYER1){
            gameBoard.at(place) = 'X';
       }
        else{
           gameBoard.at(place) = 'O';
        }
        curPlay = whosTurn;
        /// TODO: Switch the turn to the other player
        if(whosTurn == PLAYER1){
            whosTurn = PLAYER2;
        }
        else{
            whosTurn = PLAYER1;
        }
        /// TODO: Output the updated board
        drawBoard(gameBoard);
     }
    /// TODO: Determine winner and output appropriate message
        if(gameWon(gameBoard) == true){
            if(curPlay == PLAYER1){
            cout << "PLAYER 1 WINS!" << endl;
            }
            else{
                cout << "PLAYER 2 WINS!" << endl;
            }
        }
        else{
            cout << "No one wins" << endl;
        }
    return 0;
}