//
// Created by Shlomi on 15/04/2021.
//

#include "iostream"
#include "unistd.h"

using namespace std;

// Bridge is a structural DP that allows to separate the abstractions from the
// Implementations so they can evolve independently.

/********** Implementation **********/
class AbstractImplementor {
public:
    virtual void implement() = 0;
};
class ConcreteImplementor1 : public AbstractImplementor {
public:
    virtual void implement() { cout << "Concrete implementation 1 to "; }
};
class ConcreteImplementor2 : public AbstractImplementor {
public:
    virtual void implement() { cout << "Concrete implementation 2 to "; }
};

/********** Abstraction **********/
class Abstraction {
protected:
public:
    virtual void operation()=0;
};
class RefinedAbstraction1 : public Abstraction {
    AbstractImplementor* implementor; 
public:
    RefinedAbstraction1(AbstractImplementor* implementor) : implementor(implementor) {}
    virtual void operation() override { implementor->implement(); cout << "Abstraction 1." << endl; }
};
class RefinedAbstraction2 : public Abstraction {
    AbstractImplementor* implementor; 
public:
    RefinedAbstraction2(AbstractImplementor* implementor) : implementor(implementor) {}
    virtual void operation() override { implementor->implement(); cout << "Abstraction 2." << endl; }
};