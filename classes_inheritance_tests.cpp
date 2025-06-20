#include <iostream>

class BaseClass {
public:
    int x;
    virtual ~BaseClass(){};
    // no virtual no polimorphism
    virtual void print_something(){
        std::cout << "BASE CLASS" << std::endl;
    }
    // without virtual derived classes always call this Base function.
    void print_2(){
        std::cout << "PRINT BASE" << std::endl;
    }

    // implementation is mandatory when = 0
    // called abstract class, no instances allowed
    // if we don't use = 0 we can create objects of BaseClass, but now we can't due the = 0
    virtual void pure_virtual() = 0;
};

class DerivedClass : public BaseClass {
    void print_something() override {
        std::cout << "DERIVED CLASS " << std::endl;
    }

    void print_2() {
        std::cout << "PRINT DERIVED" << std::endl;
    }

    void pure_virtual(){

    }
};
const int x=5;
int main(int a, char** ar){
    // o is created by copy o is object of type BaseClass
    // BaseClass o = DerivedClass();
    // o.print_something();

    // allow virtual to pointers, o2 is object of type DerivedClass
    BaseClass* o2 = new DerivedClass;
    o2->print_something();
    o2->print_2();
    delete o2;

}