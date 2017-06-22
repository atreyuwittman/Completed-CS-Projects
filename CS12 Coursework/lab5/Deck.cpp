#include <algorithm>
#include <vector>
#include <string>
#include "Deck.h"
using namespace std;
    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
    */
    Deck::Deck(){
     char suit = 'a';
      for(unsigned int z = 1; z < 5; z++){
       if(z == 4){
        suit = 'c';
       }
       if(z == 3){
        suit = 'd';
       }
       if(z == 2){
        suit = 'h';
       }
       if(z == 1){
        suit = 's';
       }
         for(unsigned int i = 13; i > 0; i--){
            theDeck.push_back(Card(suit, i));
          }
      }
    }
    /* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
    */
    Card Deck::dealCard(){
     Card CardDealt = theDeck.back();
     theDeck.pop_back();
     dealtCards.push_back(CardDealt);
     return CardDealt;
    }


    /* Places all cards back into theDeck and shuffles them into random order.
    */
    void Deck::shuffleDeck(){
     reverse(dealtCards.begin(), dealtCards.end());
     for(unsigned int i = 0; i < dealtCards.size(); i++){
      theDeck.push_back(dealtCards.at(i));
     }
     dealtCards.resize(0);
     random_shuffle(theDeck.begin(), theDeck.end());
    }


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    unsigned Deck::deckSize() const{
     return theDeck.size();
    }
    