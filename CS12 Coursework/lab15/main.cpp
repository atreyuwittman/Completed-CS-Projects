#include <iostream>
#include "Deck.h"
#include <cstdlib>

using namespace std;

void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end){
    unsigned int mergedSize = end - begin + 1;    
   vector<Card> mergedNumbers(mergedSize);  
   unsigned int mergePos = 0;              
   unsigned int leftPos = 0;               
   unsigned int rightPos = 0;                
   
   leftPos = begin;                    
   rightPos = mid + 1;      
   while (leftPos <= mid && rightPos <= end) {
      if(v.at(leftPos).getSuit() < v.at(rightPos).getSuit()) {
         mergedNumbers.at(mergePos) = v.at(leftPos);
         ++leftPos;
      }
      else if(v.at(leftPos).getSuit() > v.at(rightPos).getSuit()){
         mergedNumbers.at(mergePos) = v.at(rightPos);
         ++rightPos;
      }
      else{
          if(v.at(leftPos).getRank() < v.at(rightPos).getRank()){
              mergedNumbers.at(mergePos) = v.at(leftPos);
              leftPos++;
          }
          else{
              mergedNumbers.at(mergePos) = v.at(rightPos);
              rightPos++;
          }
      }
      ++mergePos;
   }
   while (leftPos <= mid) {
      mergedNumbers.at(mergePos) = v.at(leftPos);
      ++leftPos;
      ++mergePos;
   }
   while (rightPos <= end) {
      mergedNumbers.at(mergePos) = v.at(rightPos);
      ++rightPos;
      ++mergePos;
   }
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      v.at(begin + mergePos) = mergedNumbers.at(mergePos);
   }
}

void mergeSort(vector<Card> &v, unsigned begin, unsigned end){
    unsigned int mid = 0;
   if(begin < end) {
      mid = (begin + end) / 2;            // Find midpoint 
      
      mergeSort(v, begin, mid);    // Sort left part
      mergeSort(v, mid + 1, end); // Sort right part
      merge(v, begin, mid, end);      // Merge parts
   }
}

void sortBySuit(vector<Card> &v){
    if(v.size() != 0){
        mergeSort(v, 0, v.size() - 1);
    }
}


void fillHand(vector<Card> &hand, Deck &d, unsigned handSize) {
   hand.resize(handSize);
   for (unsigned i = 0; i < hand.size(); ++i) {
      hand.at(i) = d.dealCard();
   }
}

//This is the function you implemented for PROGRAM 3
ostream & operator<<(ostream &out, const vector<Card> &dealtCards){
    if(dealtCards.size() != 0){
        for(unsigned int i = 0; i < dealtCards.size() - 1; i++){
            out << dealtCards.at(i) << ", ";
        }
        out << dealtCards.at(dealtCards.size() - 1);
        return out;
    }
    return out;
}

int main() {
   vector<Card> hand;
   Deck deck;
   int handSize;
   int seed;
   cout << "Enter seed value: ";
   cin >> seed;
   cout << endl;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(seed);
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;
   sortBySuit(hand);
   cout << hand << endl;
   return 0;
}
