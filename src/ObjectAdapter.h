//
// Created by Shlomi on 15/04/2021.
//

#include <iostream>

using namespace std;

// Object Adapter is a structural design pattern that allows objects with incompatible interfaces to collaborate.
// Namely, allows the Target do operations of different Adaptees using Different object adapters.

class AbstractAdaptee {
public:
    virtual void spcificRequest()=0;
};

class ConcreteAdaptee1 : public AbstractAdaptee {
public:
    void spcificRequest() override { cout << "ConcreteAdaptee1 operation." << endl; }
};

class ConcreteAdaptee2 : public AbstractAdaptee {
public:
    void spcificRequest() override { cout << "ConcreteAdaptee2 operation." << endl; }
};

class objTarget {
public:
    virtual void request()=0;
};

class objAdapter : public objTarget {
    AbstractAdaptee* adaptee;
public:
    objAdapter(AbstractAdaptee* adaptee) { this->adaptee = adaptee; }
    void request() override { adaptee->spcificRequest(); }
};