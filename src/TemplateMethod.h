//
// Created by Shlomi on 16/04/2021.
//

#include "iostream"

using namespace std;

// Template Method is a DP that defines the skeleton of an algorithm in the superclass but let’s subclasses override
// specific steps of the algorithm without changing its structure.

// Actually template method is just giving a name to a very fundamental concept in programming.
// DRAWBACK: template method isn't Open for expansion (O of SOLID). In this example, the fulfilment methods must return
// strings. A good example for this drawback is template sort method that have defferent comparison methods, but can
// not change the sorting algorihtm.

class AbstractClass {
public:
    // the template method is an algorithem that the subclasses fulfill.
    void TemplateMethod() { cout << primitiveOperation1() << " vs. " << primitiveOperation2(); }
public:
    virtual string primitiveOperation1() const =0;
    virtual string primitiveOperation2() const =0;
};

class ConcreteClass1 : public AbstractClass {
 protected:
    virtual string primitiveOperation1() const { return "Moshe"; }
    virtual string primitiveOperation2() const { return "Danny"; }
};

class ConcreteClass2 : public AbstractClass {
 protected:
    virtual string primitiveOperation1() const { return "Jilbert"; }
    virtual string primitiveOperation2() const { return "Putin"; }
};

void ClientCode(AbstractClass *ac) {
    // ... (do stuff)
    ac->TemplateMethod();
    // ... (do stuff)
}