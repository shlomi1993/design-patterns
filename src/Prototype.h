//
// Created by Shlomi on 15/04/2021.
//

#include "iostream"
#include <functional>

using namespace std;

// Prototype is a creational design pattern that allows cloning objects, even complex
// ones, without coupling to their specific classes.

class Prototype {  // e.g., "Shape".
protected:
    const char* description;
public:
    Prototype(const char* name) : description(name) {}
    virtual Prototype* clone() const =0;
    virtual void print() =0;
};

class ConcretePrototype1 : public Prototype {
    int data1, data2, data3;
public:
    ConcretePrototype1(int x, int y, int z) : Prototype("ConcretePrototype1") {
        data1 = x; data2 = y; data3 = z;
    }
    ConcretePrototype1() : Prototype("ConcretePrototype1") {
        data1 = 0; data2 = 0; data3 = 0;
    }
    Prototype* clone() const override {
        return (Prototype*) new ConcretePrototype1(data1, data2, data3);
    };
    void print() {
        cout << description << ": " << data1 << ", " << data2 << ", " << data3 << ". " << endl;
    }
};

class ConcretePrototype2 : public Prototype {
    int data4, data5;
public:
    ConcretePrototype2(int x, int y) : Prototype("ConcretePrototype2") {
        data4 = x; data5 = y;
    }
    ConcretePrototype2() : Prototype("ConcretePrototype2") {
        data4 = 0; data5 = 0;
    }
    Prototype* clone() const override {
        return (Prototype*) new ConcretePrototype2(data4, data5);
    };
    void print() {
        cout << description << ": " << data4 << ", " << data5 << ". " << endl;
    }
};