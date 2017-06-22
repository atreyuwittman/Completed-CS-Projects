#include <fstream>
#include <ostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Deck.h"
using namespace std;
bool hasPair(const vector<Card> &);
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
    srand(2222);
    Deck d1;
    vector<int> theDeck;
    ofstream outFS;
    vector<Card> hand;
    string fileYN = "";
    string fileName = "";
    int cardsPerHand = 0;
    int simulations = 0;
    int numPairs = 0;
    int simNum = 0;
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> fileYN;
    cout << endl;
    if(fileYN == "Yes"){
        cout << "Enter name of output file: ";
        cin >> fileName;
        cout << endl;
         outFS.open(fileName.c_str());
            if (!outFS.is_open()) {
                cout << "Could not open file " << fileName << "." << endl;
                return 1; 
                }
    }
        cout << "Enter number of cards per hand: ";
        cin >> cardsPerHand;
        cout << endl;
        cout << "Enter number of deals (simulations): ";
        cin >> simulations;
        cout << endl;
        
        
        
        
    if(fileYN == "Yes"){
        while(simNum < simulations){
            d1.shuffleDeck();
            for(int i = 0; i < cardsPerHand; i++){
                 hand.push_back(d1.dealCard());
            }
            if(hasPair(hand) == true){
                numPairs++;
                outFS << "Found Pair!! " << hand.at(0) << ", ";
                for(unsigned int x = 1; x < hand.size(); x++){
                    outFS << hand.at(x) << ", ";
                }
                outFS << hand.at(hand.size() - 1) << endl;
            }
            else{
                outFS << "             " << hand.at(0);
                for(unsigned int x = 0; x < hand.size(); x++){
                    outFS << hand.at(x) << ", ";
                }
                outFS << hand.at(hand.size() - 1) << endl;
            }
        hand.clear();
        simNum++;
    }
        outFS.close();
    }
    else{
        while(simNum < simulations){
        d1.shuffleDeck();
        for(int i = 0; i < cardsPerHand; i++){
            hand.push_back(d1.dealCard());
        }
            if(hasPair(hand) == true){
                numPairs++;
            }
            simNum++;
        hand.clear();
        }
    }      
    cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " << (static_cast<double>(numPairs) / simulations) * 100 << "%" << endl;

    
    return 0;
}

   /* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &hand){
    for(unsigned int i = 0; i < hand.size(); i++){
        for(unsigned int d = i + 1; d < hand.size(); d++){
            if(hand.at(d).getRank() == hand.at(i).getRank()){
                return true;
            }
        }
    }
        return false;

}
/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &out, const vector<Card> &dealtCards){
    for(unsigned int i = 0; i < dealtCards.size() - 1; i++){
        out << dealtCards.at(i) << ", ";
    }
    out << dealtCards.at(dealtCards.size() - 1);
    return out;
}