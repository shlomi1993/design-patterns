//
// Created by Shlomi on 16/04/2021.
//

#include "iostream"

using namespace std;

// State is a behavioral DP that let an object alter its behavior when its internal state changes. It appears as if the
// object changed its class. The idea is by given a state, activate  an operation polymorphically.

class State {
public:
    virtual void Handle() =0;
};

class Walker : public State {   // ConcreteStateA in the UMLs.
public:
    virtual void Handle() { cout << "Walking..." << endl; }
};

class Driver : public State {   // ConcreteStateA in the UMLs.
public:
    virtual void Handle() { cout << "Driving..." << endl; }
};

class Pilot : public State {   // ConcreteStateA in the UMLs.
public:
    virtual void Handle() { cout << "Fly away..." << endl; }
};

class Context {
    State *state;
public:
    Context(State *s) : state(s) {
        s->Handle();
    }
};