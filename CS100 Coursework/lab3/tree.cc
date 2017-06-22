#include <iostream>
#include <cmath>
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

int main(){

Op* num1 = new Op(3);
Op* num2 = new Op(7);
Op* num3 = new Op(4);
Op* num4 = new Op(2);
Multi* multiply = new Multi(num2, num3);
Add* add = new Add(num1, multiply);
Sub* subtract = new Sub(add, num4);
cout << subtract->evaluate() << endl;

Op* newnum1 = new Op(5);
Op* newnum2 = new Op(12);
Op* newnum3 = new Op(9);
Op* newnum4 = new Op(4);
Op* newnum5 = new Op(3);
Op* newnum6 = new Op(6);
Multi* multiply2 = new Multi(newnum2, newnum3);
Add* add1 = new Add(newnum6, multiply2);
Add* add2 = new Add(newnum1, newnum5);
Sub* subtract1 = new Sub(add1, add2);
cout << subtract1->evaluate() << endl;

return 0;
}
