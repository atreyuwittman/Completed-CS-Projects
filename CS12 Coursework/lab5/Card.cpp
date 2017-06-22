#include <string>
#include <ostream>
#include "Card.h"
using namespace std;
    /* Assigns a default value of 2 of Clubs
    */
    Card::Card(){
     rank = 2;
     suit = 'c';
    }
    /* Assigns the Card the suit and rank provided.
       suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
       If an invalid suit is provided, sets the suit to Clubs
       ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
       If an invalid rank is provided, sets the rank to 2
       Accepts lower or upper case characters for suit
    */  
    Card::Card(char a, int x){
      if(rank < 2 || rank > 13){
       rank = 2;
      }
      rank = x;
      suit = tolower(a);
      
      return;
    }
    /* Returns the Card's suit
    */
    char Card::getSuit() const{
     return suit;
    }
    /* Returns the Card's rank as an integer
    */
    int Card::getRank() const{
     return rank;
    }

    /* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
    */  
    ostream & operator<<(ostream &out, const Card &cardShown){
	     char z = cardShown.getSuit();
	     string suitName = "";
	     if(z == 'c'){
	      suitName = "Clubs";
	     }
	     if(z == 'h'){
	      suitName = "Hearts";
	     }
	     if(z == 's'){
	      suitName = "Spades";
	     }
	     if(z == 'd'){
	      suitName = "Diamonds";
	     }
	     if(cardShown.getRank() == 1){
	      out << "Ace" << " of " << suitName;
	     }
	     else if(cardShown.getRank() == 11){
	      out << "Jack" << " of " << suitName;
	     }
	     else if(cardShown.getRank() == 12){
       out << "Queen" << " of " << suitName;
	     }
	     else if(cardShown.getRank() == 13){
	      out << "King" << " of " << suitName;
	     }
	     else{
	     out << cardShown.getRank() << " of " << suitName;
	     }
	     return out;
    }