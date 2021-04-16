//
// Created by Shlomi on 16/04/21.
//

#include <iostream>
#include <cstring>

using namespace std;

// Decorator is a structural DP that gives the ability to create a behaviour by combination of different defined
// behaviours on runtime. It allows to avoid an exponential number of classes.

class AbstractComponent {   // E.g., "Shake", "Pizza".
public:
    virtual int getNumericState()=0;    // E.g., "Price".
    virtual string getDescription()=0;  // E.g, kind of topping.
};

class ConcreteComponentA : public AbstractComponent {
    int getNumericState() { return 10; }
    string getDescription() { return "ConcreteComponentA "; }
};

class ConcreteComponentB : public AbstractComponent {
    int getNumericState() { return 5; }
    string getDescription() { return "ConcreteComponentB "; }
};

class AbstractComponentDecorator : public AbstractComponent {
protected:
    AbstractComponent* ac;
public:
    virtual int getNumericState()=0;
    virtual string getDescription()=0;
};

class ConcreteComponentDecoratorA : public AbstractComponentDecorator {
public:
    ConcreteComponentDecoratorA(AbstractComponent* acd) { ac = acd; }
    int getNumericState() { return ac->getNumericState() + 3; }
    string getDescription() { return ac->getDescription() + "+ DecoratorA added behaviour "; }
};

class ConcreteComponentDecoratorB : public AbstractComponentDecorator {
public:
    ConcreteComponentDecoratorB(AbstractComponent* acd) { ac = acd; }
    int getNumericState() { return ac->getNumericState() + 2; }
    string getDescription() { return ac->getDescription() + "+ DecoratorB added behaviour "; }
};

class ConcreteComponentDecoratorC : public AbstractComponentDecorator {
public:
    ConcreteComponentDecoratorC(AbstractComponent* acd) { ac = acd; }
    int getNumericState() { return ac->getNumericState() + 1; }
    string getDescription() { return ac->getDescription() + "+ DecoratorC added behaviour "; }
};