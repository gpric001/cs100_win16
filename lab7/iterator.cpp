#include "iterator.h"
#include <iostream>

//OperatorIterator class method definitions
OperatorIterator::OperatorIterator(Base* ptr) : Iterator(ptr) {}

void OperatorIterator::first(){ this->current_ptr = this->self_ptr->get_left(); }

void OperatorIterator::next(){
   if(this->current_ptr == this->self_ptr->get_left())
      this->current_ptr = this->self_ptr->get_right();
   else {
       this->current_ptr = NULL;}
}

bool OperatorIterator::is_done(){ return this->current_ptr == NULL; }

Base* OperatorIterator::current(){ return this->current_ptr; }

//UnaryIterator class method definition
UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {}

void UnaryIterator::first(){ this->current_ptr = this->self_ptr->get_left(); }

void UnaryIterator::next(){ this->current_ptr = NULL; }

bool UnaryIterator::is_done(){ return this->current_ptr == NULL; }

Base* UnaryIterator::current(){ return this->current_ptr; }

//NullIterator class method definitions
NullIterator::NullIterator(Base* ptr) : Iterator(ptr) { this->current_ptr = NULL; }

void NullIterator::first(){ return; }

void NullIterator::next(){ return; }

bool NullIterator::is_done(){ return true; }

Base* NullIterator::current(){ return NULL; }

//PreOrderIterator class method definitions
PreOrderIterator::PreOrderIterator(Base * ptr) : Iterator(ptr) {}

void PreOrderIterator::first(){
   //Empty stack
   while(!iterators.empty()){ iterators.pop(); }

   //Create an iterator for the Base* that we built the iterator for
   Iterator* itr = this->self_ptr->create_iterator();

   //Initizlize that iterator and push it onto the stack
   itr->first();
   iterators.push(itr);
}

void PreOrderIterator::next(){
   //Get the top iterator on the stack
   Iterator* itr = iterators.top();
      
   //Push the iterator of the collection that itr is currently pointing to
   //onto the stack
   if(itr->current() != NULL){
      iterators.push(itr->current()->create_iterator());
      iterators.top()->first();
   }

   //Advance itr
   itr->next();

   //As long as the top iterator on the stack points to NULL, pop it off.
   while(!iterators.empty() && iterators.top()->is_done()) { iterators.pop(); } 
}

bool PreOrderIterator::is_done(){
    return iterators.empty();
}

Base* PreOrderIterator::current(){ return iterators.top()->current(); }
