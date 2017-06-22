#include <iostream>
#include <math.h>
#include <vector>
#include <list>
#include <cmath>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <string.h>

using namespace std;

class Base {
	public:
		Base() {};
		virtual double evaluate() = 0;
};

class Op: public Base{
	private:
		double value;
	public:
		Op(double n){
			value = n;
		}

		double evaluate(){
			return value;
		}
};

class Multi: public Base{
	protected:
		Base* left;
		Base* right;
	public:
		Multi(Base* l, Base* r){
			left = l;
			right = r;
		}
		double evaluate(){
			return (*left).evaluate() * (*right).evaluate();
		} 

};

class Div: public Base{
	protected:
		Base* left;
		Base* right;
	public:
		Div(Base* l, Base* r){
			left = l;
			right = r;
		}
		double evaluate(){
			return (*left).evaluate() / (*right).evaluate();
		}

};

class Add: public Base{
	protected:
		Base* left;
		Base* right;
	public:
		Add(Base* l, Base* r){
			left = l;
			right = r;
		}
		double evaluate(){
			return (*left).evaluate() + (*right).evaluate();
		}

};

class Sub: public Base{
	protected:
		Base* left;
		Base* right;
	public:
		Sub(Base* l, Base* r){
			left = l;
			right = r;
		}
		double evaluate(){
			return (*left).evaluate() - (*right).evaluate();
		}

};

class Sqr: public Base{
	protected:
		Base* v;
	public:
		Sqr(Base* value){
			v = value;
		}
		double evaluate(){
			return (*v).evaluate() * (*v).evaluate();
		}
};
class BasePrint {
	private:
		/* Value to Print */
		double value;

	public:
		/* Constructors */
		BasePrint(){}
		BasePrint(double val){
			value = val;
		}
		
		/* Pure Virtual Print Function */
		virtual void print() = 0;
};
class BinaryPrint: public BasePrint {
	private:
		/* Value to Print */
		double value;

	public:
		/* Constructors */
		BinaryPrint():BasePrint(){}
		BinaryPrint(double val){
			value = val;
		}
		
		/* Pure Virtual Print Function */
		void print(){
			cout << bitset<16>(value) << endl;
		}
};
class DoublePrint: public BasePrint {
	private:
		/* Value to Print */
		double value;

	public:
		/* Constructors */
		DoublePrint():BasePrint(){}
		DoublePrint(double val){
			value = val;
		}
		
		/* Pure Virtual Print Function */
		void print(){
			cout << value << endl;
		}
};
class HexPrint: public BasePrint {
	private:
		/* Value to Print */
		double value;

	public:
		/* Constructors */
		HexPrint():BasePrint(){}
		HexPrint(double val){
			value = val;
		}
		
		/* Pure Virtual Print Function */
		void print(){
			int a = value;
			cout << std::hex << a << endl;
		}
};
class BaseFactory {
	public:
		/* Constructor */
		BaseFactory(){}

		/* Pure Virtual Generate Function */
		virtual BasePrint* generatePrint(double value) = 0;
};
class BinaryFactory: public BaseFactory {
	public:
		/* Constructor */
		BinaryFactory(): BaseFactory(){}

		/* Pure Virtual Generate Function */
		BasePrint* generatePrint(double value){
			BinaryPrint* bin = new BinaryPrint(value);
			return bin;
		}
};
class HexFactory: public BaseFactory  {
	public:
		/* Constructor */
		HexFactory(): BaseFactory(){}

		/* Pure Virtual Generate Function */
		BasePrint* generatePrint(double value){
			HexPrint* hexing = new HexPrint(value);
			return hexing;
		}
};
class DoubleFactory: public BaseFactory  {
	public:
		/* Constructor */
		DoubleFactory(): BaseFactory(){}

		/* Pure Virtual Generate Function */
		BasePrint* generatePrint(double value){
			DoublePrint* doub = new DoublePrint(value);
			return doub;
		}
};
class Sort;

class Container {
	protected:
		Sort* sort_function;
		BaseFactory* BaseFact;
	public:
		Container(BaseFactory* BaseFact) : sort_function(NULL), BaseFact(BaseFact){};
		Container(Sort* function) : sort_function(function){};

		void set_sort_function(Sort* sort_function);
		virtual void add_element(Base* element) = 0;
		virtual void print() = 0;
		virtual void sort() = 0;
		virtual void swap(int i, int j) = 0;
		virtual Base* at(int i) = 0;
		virtual int size() = 0;
};

void Container::set_sort_function(Sort* sort_function){
	this->sort_function = sort_function;
}

class VectorContainer: public Container {
	private:
		vector <Base*> treeVector;
	public:
	VectorContainer(BaseFactory* BaseFact): Container(BaseFact){}
	void add_element(Base* object){
		treeVector.push_back(object);
	}

	void print(){
		for(unsigned int i=0;i<treeVector.size();i++){
			cout << "Tree " << i << " outputs: ";
			this->BaseFact->generatePrint(treeVector.at(i)->evaluate())->print();
		}
	}

	void sort();

	void swap(int i, int j){
		if((unsigned int)i >= treeVector.size() || (unsigned int)j >= treeVector.size() || i < 0 || j < 0 ) {
			cout << "Indices out of bounds" << endl;
			return;
		}
		Base* temp;
		temp = treeVector[i];
		treeVector[i] = treeVector[j];
		treeVector[j] = temp;
	}

	Base* at(int i){
		if((unsigned int)i >= treeVector.size() || i < 0){
			cout << "Index out of bounds" << endl;
			return NULL;
		}
		return treeVector[i];
	}

	int size(){
		return (int)treeVector.size();
	}

};

class ListContainer: public Container {
	private:
		list<Base*> treeList;
	public:
	ListContainer(BaseFactory* BaseFact): Container(BaseFact){}
	void add_element(Base* object){
		treeList.push_back(object);
	}

	void print(){
		int j = 0;
		for(list<Base*>::iterator i=treeList.begin();i!=treeList.end();++i){
			j++;
			cout << "Tree " << j << " outputs: ";
			BaseFact->generatePrint((*i)->evaluate())->print();
		}
	}

	void sort();

	void swap(int i, int j){
		if((unsigned int)i >= treeList.size() || (unsigned int)j >= treeList.size() || i < 0 || j < 0 ) {
			cout << "Indices out of bounds" << endl;
			return;
		}
		list<Base*>::iterator iIter=treeList.begin();
		list<Base*>::iterator jIter=treeList.begin();

		for(int k=0;k<i;k++){
			iIter++;
		}
		for(int k=0;k<j;k++){
			jIter++;
		}

		Base* temp;
		temp = (*iIter);
		(*iIter) = (*jIter);
		(*jIter) = temp;
	}

	Base* at(int i){
		if((unsigned int)i >= treeList.size() || i < 0){
			cout << "Index out of bounds" << endl;
			return NULL;
		}
		list<Base*>::iterator Iter = treeList.begin();
		for(int k=0;k<i;k++){
			Iter++;
		}

		return (*Iter);
	}

	int size(){
		return (int)treeList.size();
	}

};


class Sort {
	public:
		Sort();
		virtual void sort(Container* contain) = 0;
	
};

Sort::Sort(){}

class SelectionSort: public Sort {
	public:

		void sort(Container* contain){
			int i, j, begin;
			for(i=contain->size()-1;i>0;i--){
				begin = 0;
				for (j=1;j<=i; j++){
					if((contain->at(j)->evaluate())<(contain->at(begin)->evaluate())){
						begin = j;
					}
				}
				contain->swap(begin, i);
			}
		}

};

class BubbleSort: public Sort {
	public:

		void sort(Container* contain){
			int i, j, F=1;
			for(i=1;(i <= contain->size()) && F;i++){
				F = 0;
				for(j=0; j < (contain->size()-1);j++){
					if((contain->at(j+1)->evaluate()) > (contain->at(j)->evaluate())){
						contain->swap(j, j+1);
						F = 1;
					}
				}
			}
		}

};

void ListContainer::sort(){
	sort_function->sort(this);	
}

void VectorContainer::sort(){
	sort_function->sort(this);	
}
class Ceil : public Base { 
    private:
        double value; 
        
    public: 
        Ceil(double v) {
            value = v;    
        }
        
        double evaluate() {
            return ceil(value); 
        }
        
    
}; 
class Floor : public Base { 
    private:
        double value; 
        
    public: 
        Floor(double v) {
            value = v;    
        }
        
        double evaluate() {
            return floor(value); 
        }
        
    
}; 
class Abs : public Base { 
    private:
        double value; 
        
    public: 
        Abs(double v) {
            value = v;    
        }
        
        double evaluate(){
            return abs(value);
        }
        
    
};



int main(int argc, char* argv[]) {
    
    /* Read in the input flag */
	char* s = argv[1];
    
    /* Create and set the Factory */
	BaseFactory* baf = NULL;
	if(strcmp(s,"d")==0){
		baf = new DoubleFactory();
	}else if(strcmp(s,"h")==0){
		baf = new HexFactory();
	}else{
		baf = new BinaryFactory();
	}
    
    /* Create the elements for testing */
	Op* op1 = new Op(5);
	Op* op2 = new Op(2);
	Op* op3 = new Op(4);
	Op* op4 = new Op(6);
	Multi* A = new Multi(op1, op2);
	Sub* B = new Sub(op3, op4);
	Add* C = new Add(A, B);
	Sqr* D = new Sqr(C);

    /* Save the elements to the container */
	VectorContainer* container = new VectorContainer(baf);
	container->add_element(A);
	container->add_element(B);
	container->add_element(D);
    
    /* Print the container before it is sorted */
	cout << "Container Before Sort: " << endl;
	container->print();
    
    /* Print the container after it is sorted */
    cout << "Container After Sort: " << endl;
	container->set_sort_function(new BubbleSort());
	container->sort();
	container->print();
}
;

