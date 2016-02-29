#include <iostream>
#include <vector>
#include "composite.h"

using namespace std;

int main() {

	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2); 
   Add* add1 = new Add(op3, op4);
   Sqr* sqr1 = new Sqr(op2);
	Sub* sub1 = new Sub(add1, sqr1);
	Root* root1 = new Root(sub1);

   Op* op5 = new Op(5);
   Op* op6 = new Op(6);
   Op* op7 = new Op(7);
   Op* op8 = new Op(8);
   Mult* mul1 = new Mult(op5, op6);
   Sub* sub2 = new Sub(op7, op8);
   Sqr* sqr2 = new Sqr(mul1);
   Add* add2 = new Add(sqr2, sub2);	
   Root* root2 = new Root(add2);

   Op* op0 = new Op(0);
   Op* op11 = new Op(11);
   Op* op13 = new Op(13);
   Op* op81 = new Op(81);
   Sub* sub3 = new Sub(op7, op13);
   Sqr* sqr3 = new Sqr(op11);
   Sub* sub4 = new Sub(op81, op0);
   Mult* mul2 = new Mult(sub4, sqr3);
   Sqr* sqr4 = new Sqr(sub3);
   Add* add3 = new Add(mul2, sqr4);
   Root* root3 = new Root(add3);

   Op* op1 = new Op(1);
   Mult* mul3 = new Mult(op0, op1);
   Sub* sub5 = new Sub(op1, mul3);
   Sqr* sqr5 = new Sqr(sub5);
   Root* root4 = new Root(sqr5);
    
	cout << "--- PreOrder Iteration Test 1---" << endl;
	PreOrderIterator* pre_itr = new PreOrderIterator(root1);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		pre_itr->current()->print();
		cout << endl;
	}
   cout << endl;
	cout << "--- PreOrder Iteration Test 2---" << endl;
	pre_itr = new PreOrderIterator(root2);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		pre_itr->current()->print();
		cout << endl;
	}
   cout << endl;
	cout << "--- PreOrder Iteration Test 3---" << endl;
	pre_itr = new PreOrderIterator(root3);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		pre_itr->current()->print();
		cout << endl;
	}
   cout << endl;
	cout << "--- PreOrder Iteration Test 4---" << endl;
	pre_itr = new PreOrderIterator(root4);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		pre_itr->current()->print();
		cout << endl;
	}
};
