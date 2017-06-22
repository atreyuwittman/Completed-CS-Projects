#include <ostream>
#include "IntList.h"
using namespace std;


IntList::IntList(){
    head = 0;
}
   /* Inserts a data value to the front of the list.
   */
void IntList::push_front(int value){
    IntNode * tmp = new IntNode(value);
    tmp-> next = this-> head;
    this->head = tmp;
}
   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
ostream & operator<<(ostream &out, const IntList &rhs){
    if(rhs.head == 0){
        return out;
    }
    else{
    out << rhs.head->data<<rhs.head->next;
    return out;
    }
}

   /* Returns true if the integer passed in is contained within the IntList, 
      otherwise returns false.
   */
bool IntList::exists(int value) const{
    return exists(head, value);
}

   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in,
      otherwise returns false.
   */
bool IntList::exists(IntNode *curr, int value) const{
       if(curr == 0){
           return false;
       }
       if(curr->data == value){
        return true;
       }
       else{
           return exists(curr->next, value);
       }
  }

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode *curr){
    if(curr == 0){
        return out;
    }
    out << ' ' << curr->data<<curr->next;
    return out;
}