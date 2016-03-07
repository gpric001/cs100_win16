#include "visitor.h"

PrintVisitor::PrintVisitor() {};

void PrintVisitor::rootNode(){
   this->output.append("Root-> ");   
}

void PrintVisitor::sqrNode(){
   this->output.append("^2 ");
}

void PrintVisitor::multNode(){
   this->output.append("* ");
}

void PrintVisitor::subNode(){
   this->output.append("- ");  
}

void PrintVisitor::addNode(){
   this->output.append("+ ");
}

void PrintVisitor::opNode(Op* op){
   std::ostringstream strs;
   strs << op->evaluate();
   this->output.append(strs.str() + " ");
}

void PrintVisitor::execute(){
   std::cout<<this->output<<std::endl;
}
