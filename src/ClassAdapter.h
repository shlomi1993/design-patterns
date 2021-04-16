//
// Created by Shlomi on 15/04/2021.
//

#include <iostream>

using namespace std;

// Class Adapter is a structural design pattern that allows objects with incompatible interfaces
// to collaborate. Namely, allows the Target do an operation of the Adaptee using Class Adapter.

class Adaptee {
public:
    void operation() { cout << "Adaptee operation" << endl; }
};

class Target {
public:
    virtual void request()=0;
};

class Adapter : public Target {
    Adaptee *adaptee;
public:
    Adapter() { adaptee = new Adaptee(); }
    void request() override { adaptee->operation(); }
    ~Adapter() { delete adaptee; }
};

// The problem with class adapter is that it is not allow to the Taeget use multiple Adapters.