#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
		OpCommand(int value){
			root = new Op(value);
		}
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
		AddCommand(Command* newCom, int a){
			Base* Iter = new Op(a);
			Base* BaseIn = new Op(newCom->execute());
			Add* AddResult = new Add(Iter, BaseIn);
			root = new Op(AddResult->evaluate());
		}
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
	SubCommand(Command* newCom, int a){
			Base* Iter = new Op(a);
			Base* BaseIn = new Op(newCom->execute());
			Sub* SubResult = new Sub(Iter, BaseIn);
			root = new Op(SubResult->evaluate());
		}
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
	MultCommand(Command* newCom, int a){
			Base* Iter = new Op(a);
			Base* BaseIn = new Op(newCom->execute());
			Mult* MultResult = new Mult(Iter, BaseIn);
			root = new Op(MultResult->evaluate());
		}
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
	SqrCommand(Command* newCom){
			Base* BaseIn = new Op(newCom->execute());
			Sqr* SqrResult = new Sqr(BaseIn);
			root = new Op(SqrResult->evaluate());
		}
};

#endif //__COMMAND_CLASS__
