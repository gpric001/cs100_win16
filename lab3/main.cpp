#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>

class Base {
    public:
    /* Constructors */
    Base() {};

    /* Pure Virtual Functions */
    virtual double evaluate() = 0;
};

class Operand: public Base {
    public:
     Operand(double val){
        data = val;
    }

    double evaluate(){
        return data;
    }
    private:
        double data;
};

class Operator1: public Base {
    public:
        Base* val;
        Operator1(Base* a){
            val = a;
        }
};

class Operator2: public Base {
    public:
        Base* val1;
        Base* val2;
        Operator2(Base* a, Base* b){
            val1 = a;
            val2 = b;
        }
};

class Mult: public Operator2 {
    public:
        Mult(Base* a, Base* b): Operator2(a, b){}
        double evaluate(){
            return val1->evaluate() * val2->evaluate();
        }
};

class Div: public Operator2 {
    public:
       Div(Base* a, Base* b): Operator2(a, b){}
        double evaluate(){
            return val1->evaluate() / val2->evaluate();
        }
};

class Add: public Operator2 {
    public:
        Add(Base* a, Base* b): Operator2(a, b){}
        double evaluate(){
            return val1->evaluate() + val2->evaluate();
        }
};

class Sub: public Operator2 {
    public:
        Sub(Base* a, Base* b): Operator2(a, b){}
        double evaluate(){
            return val1->evaluate() - val2->evaluate();
        }
};

class Sqr: public Operator1 {
    public:
        Sqr(Base* a): Operator1(a){};
        double evaluate(){
            return val->evaluate() * val->evaluate();
        }
};

class Sort;

class Container {
    protected:
      Sort* sort_function;

    public:
      Container() : sort_function(NULL) {};
      Container(Sort* function) : sort_function(function) {};

      void set_sort_function(Sort* sort_function);

      virtual void add_element(Base* element) = 0;
      virtual void print() = 0;
      virtual void sort() = 0;
      virtual void swap(int i, int j) = 0;
      virtual Base* at(int i) = 0;
      virtual int size() = 0;
};

class Sort {
    public:
      Sort(){};

      virtual void sort(Container* container) = 0;
};

class Vcontainer : public Container{

private:

    std::vector <Base*> eles;

public:

    Vcontainer() : Container (){};

    Vcontainer(Sort * function) :Container(function){};

    
    void set_sort_function(Sort* function){
        sort_function = function;
    }

    void add_element(Base* element)

    {

        eles.push_back(element);

    }

    void print()

    {

        std::vector<Base *>::iterator it;

        for(it=eles.begin();it!=eles.end();it++)

        {

            std::cout<<(*it)->evaluate()<<std::endl;

        }

    }

    void sort(){

        sort_function->sort(this);

    }

    void swap(int i,int j){

        

        std::swap(eles[i],eles[j]);

    }

    Base* at(int i)

    {

        return eles.at(i);

    }

    int size()

    {

        return eles.size();

    }

};

class Lcontainer: protected Container {
    public:
      Lcontainer() : Container() {};
      Lcontainer(Sort* function) : Container(function) {};

    void set_sort_function(Sort* function){
        sort_function = function;
    }

    void add_element(Base* element){
        elems.push_back(element);
    }

    void print(){
        std::list<Base*>::iterator it;
        for(it = elems.begin(); it != elems.end(); it++){
            std::cout<<(*it)->evaluate()<<std::endl;
        }
    }
 
    void sort(){
        sort_function->sort(this);
    }

    void swap(int i, int j){
        std::list<Base*>::iterator iti = elems.begin();
        std::list<Base*>::iterator itj = elems.begin();
        for(int n = 0;n<i;n++)
            iti++;
        for(int m = 0;m<j;m++)
            itj++;
        std::iter_swap(iti,itj); 
    }

     Base* at(int i){
        std::list<Base*>::iterator it = elems.begin();
        for(int j = 0;j<i;j++)
            it++;
        return *it;
    }

    int size(){
        return elems.size();
    }

    private:
      std::list<Base*> elems;
};

class InsertSort: public Sort{
    void sort(Container* container){
        for(int i = 1; i < container->size(); i++){
            for(int j = i; j > 0; j--){
                if(container->at(j)->evaluate() < container->at(j - 1)->evaluate())
                   container->swap(j, j - 1);
                else
                   break;
            }
        }        
    }
};

class BubbleSort: public Sort{
    void sort(Container* container){
        int flag = 1;
        for(int i = 1; i < container->size() && flag; i++){
            flag = 0;
            for(int j = 0; j < (container->size() - 1); j++){
                if(container->at(j + 1)->evaluate() > container->at(j)->evaluate()){
                    container->swap(j, j + 1);
                    flag = 1;
                }
            }
        }
    }
};

int main(int argc, char **argv){
    Operand o1(6);
    Operand o2(8);
    Operand o3(4);
    Operand o4(5);
    Operand o5(3);
    Mult m(&o1,&o2);
    Add a(&m,&o3);
    Add a2(&o2,&o3);
    Sqr sq(&a2);
    Div div(&m,&o3);
    Add a3(&div,&o4);
    Sqr sq2(&o5);
    Sub sub(&a3,&sq2);
    std::cout<<a.evaluate()<<std::endl;
    std::cout<<sq.evaluate()<<std::endl;
    std::cout<<sub.evaluate()<<std::endl<<std::endl;
    
    InsertSort iSort;
    Lcontainer lcon(&iSort);
    lcon.add_element(&o1);
    lcon.add_element(&sub);
    lcon.add_element(&div);
    lcon.add_element(&sq2);
    lcon.add_element(&m);
    std::cout<<lcon.at(0)->evaluate()<<std::endl;
    std::cout<<lcon.at(1)->evaluate()<<std::endl<<std::endl;

    lcon.print();
    std::cout<<std::endl;

    lcon.swap(0,1);
    lcon.print();
    std::cout<<std::endl;

    lcon.sort();
    lcon.print();
    std::cout<<std::endl;

    BubbleSort bSort;
    lcon.set_sort_function(&bSort);
    lcon.sort();
    lcon.print();
    std::cout<<std::endl;

    std::cout<<"Vector Container"<<std::endl;

    Vcontainer vcon(&iSort);
    vcon.add_element(&o1);
    vcon.add_element(&sub);
    vcon.add_element(&div);
    vcon.add_element(&sq2);
    vcon.add_element(&m);
    std::cout<<vcon.at(0)->evaluate()<<std::endl;
    std::cout<<vcon.at(1)->evaluate()<<std::endl<<std::endl;

    vcon.print();
    std::cout<<std::endl;

    vcon.swap(0,1);
    vcon.print();
    std::cout<<std::endl;

    vcon.sort();
    vcon.print();
    std::cout<<std::endl;

    vcon.set_sort_function(&bSort);
    vcon.sort();
    vcon.print();
    std::cout<<std::endl;

}



