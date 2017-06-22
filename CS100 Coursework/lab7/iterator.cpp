#include "iterator.h"

OperatorIterator::OperatorIterator(Base* ptr):Iterator(ptr){}
void OperatorIterator::first(){
	this->current_ptr = this->self_ptr->get_left();
}
void OperatorIterator::next(){
	if(this->current_ptr == this->self_ptr->get_left())
		this->current_ptr = this->self_ptr->get_right();
	else if(this->current_ptr == this->self_ptr->get_right())
		this->current_ptr = NULL;
	else{
		cout << "ERROR: last element" << endl;
		cout << "Use 'is_done'" <<endl;
	}
		
}
bool OperatorIterator::is_done(){
	if(this->current_ptr == NULL)
		return true;
	return false;
}
Base* OperatorIterator::current(){
	return current_ptr;
}

UnaryIterator::UnaryIterator(Base* ptr):Iterator(ptr){}
void UnaryIterator::first(){
	this->current_ptr = this->self_ptr->get_left();
}
void UnaryIterator::next(){
	this->current_ptr = NULL;
}
bool UnaryIterator::is_done(){
	if(this->current_ptr == NULL)
		return true;
	return false;
}
Base* UnaryIterator::current(){
	return current_ptr;
}

NullIterator::NullIterator(Base* ptr):Iterator(ptr){}
void NullIterator::first(){ }
void NullIterator::next(){ this->current_ptr = NULL; }
bool NullIterator::is_done(){
	return true;
}
Base* NullIterator::current(){
	return current_ptr;
}
PreOrderIterator::PreOrderIterator(Base* ptr):Iterator(ptr){}
void PreOrderIterator::first() { 
	//Empty the stack (just in case we had something leftover from
	//another run)
 
	//Create an iterator for the Base* that we built the iterator for
 
	//Initialize that iterator and push it onto the stack
	if(self_ptr->get_left() == NULL)
    {
        return;
    }
    while(!iterators.empty())
    {
        iterators.pop();
    }
    Iterator* i = self_ptr->create_iterator();
    i->first();
    iterators.push(i);

}
 
void PreOrderIterator::next() { 
	//Create an iterator for the item on the top of the stack
 
	//Initialize the iterator and push it onto the stack
 
	//As long as the top iterator on the stack is done, pop it off the
	//stack and then advance whatever iterator is now on top of the stack
	if(iterators.size() == 0)
    {
        return;
    }
    
    Iterator* i = iterators.top()->current()->create_iterator();
    i->first();
    iterators.push(i);
    while(iterators.size() > 0 && iterators.top()->is_done())
    {
        iterators.pop();
        if(iterators.size() == 0)
        {
            return;
        }
//
        
     iterators.top()->next();
    
        
    }
}
 
bool PreOrderIterator::is_done() { 
	//Return true if there are no more elements on the stack to iterate
	if(iterators.empty())
	{
		return true;
	}

	return false;
}
 
Base* PreOrderIterator::current() { 
	//Return the current for the top iterator in the stack
	    return iterators.top()->current();
}