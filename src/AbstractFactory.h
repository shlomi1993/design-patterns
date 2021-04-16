//
// Created by Shlomi on 15/04/2021.
//

#include "iostream"

using namespace std;

// Abstract Factory is a creational design pattern, which solves the problem of
// creating entire product families without specifying their concrete classes.

class AbstractProductA {
public:
    virtual string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    string UsefulFunctionA() const override { return "A1 "; }
};

class ConcreteProductA2 : public AbstractProductA {
    string UsefulFunctionA() const override { return "A2 "; }
};

class AbstractProductB {
public:
    virtual string UsefulFunctionB() const = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    string UsefulFunctionB() const override { return "B1 "; }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    string UsefulFunctionB() const override { return "B2 "; }
};

class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() const = 0;
    virtual AbstractProductB* CreateProductB() const = 0;
};


class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override { return new ConcreteProductA1(); }
    AbstractProductB* CreateProductB() const override { return new ConcreteProductB1(); }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() const override { return new ConcreteProductA2(); }
    AbstractProductB* CreateProductB() const override { return new ConcreteProductB2(); }
};