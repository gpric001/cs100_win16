#ifndef _VISITOR_H_
#define _VISITOR_H_

#include <string>
#include <iostream>
#include <sstream>
#include "composite.h"

class Op;
 
class Visitor{
    public:
      virtual void rootNode() = 0;
      virtual void sqrNode() = 0;
      virtual void multNode() = 0;
      virtual void subNode() = 0;
      virtual void addNode() = 0;
      virtual void opNode(Op* op) = 0;
      virtual void execute() = 0;
};

class PrintVisitor : public Visitor {
    private:
      std::string output;

    public:
      PrintVisitor();

      void rootNode();
      void sqrNode();
      void multNode();
      void subNode();
      void addNode();
      void opNode(Op* op);

      void execute();
};

#endif
