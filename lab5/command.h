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
    public:
        OpCommand(double val): Command(){
            root = new Op(val);
        }
};

class AddCommand : public Command {
    public:
        AddCommand(Command* cmd, double val){
            root = new Add(cmd->get_root(), new Op(val));
        }
};

class SubCommand : public Command {
    public:
        SubCommand(Command* cmd, double val){
            root = new Sub(cmd->get_root(), new Op(val));
        }
};

class MultCommand : public Command {
    public:
        MultCommand(Command* cmd, double val){
            root = new Mult(cmd->get_root(), new Op(val));
        }
};

class SqrCommand : public Command {
    public:
        SqrCommand(Command* cmd){
            root = new Sqr(cmd->get_root());
        }
};

#endif //__COMMAND_CLASS__
