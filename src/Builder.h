//
// Created by Shlomi on 15/04/2021.
//

#include "iostream"

using namespace std;

// Builder is a creational design pattern, which allows constructing complex objects step by step. In fact, Builder DP
// is Bridge DP with the context of creational DP.

// Here is a product with multiple components.
struct ComplexProduct {
    const bool component1;
    const bool component2;
    const bool component3;
    const bool component4;
    ComplexProduct(bool c1, bool c2, bool c3, bool c4) : component1(c1),component2(c2),component3(c3),component4(c4) {}
    void print() const {
        cout << "ComplexProduct states:" << endl;
        cout << " * component1: " << (component1 ? "+" : "-") << endl;
        cout << " * component2: " << (component2 ? "+" : "-") << endl;
        cout << " * component3: " << (component3 ? "+" : "-") << endl;
        cout << " * component4: " << (component4 ? "+" : "-") << endl;
    }
};

// Option 1: each build method returns a ComplexBuilder allowing chain construction, but deviates from the UML.
class ComplexBuilder {
    bool component1;
    bool component2;
    bool component3;
    bool component4;
public:
    ComplexBuilder() {
        component1 = false;
        component2 = false;
        component3 = false;
        component4 = false;
    }
    virtual ComplexBuilder BuildPart1() { component1 = true; return *this; }
    virtual ComplexBuilder BuildPart2() { component2 = true; return *this; }
    virtual ComplexBuilder BuildPart3() { component3 = true; return *this; }
    virtual ComplexBuilder BuildPart4() { component4 = true; return *this; }
    virtual ComplexProduct* GetProduct() const {return new ComplexProduct(component1,component2,component3,component4);}
};
class Director {
    ComplexBuilder cb;
public:
    Director(ComplexBuilder cb) : cb(cb) {}
    ComplexProduct* construct() { return cb.BuildPart3().BuildPart1().BuildPart4().BuildPart2().GetProduct(); }
};

// Option 2: works according to the UML but not allow chain construction.
class Builder {
protected:
    bool component1;
    bool component2;
    bool component3;
    bool component4;
public:
    virtual void BuildPart1() =0;
    virtual void BuildPart2() =0;
    virtual void BuildPart3() =0;
    virtual void BuildPart4() =0;
    virtual ComplexProduct* GetProduct() const =0;
};
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() {
        component1 = false;
        component2 = false;
        component3 = false;
        component4 = false;
    }
    virtual void BuildPart1() { component1 = true; }
    virtual void BuildPart2() { component2 = true; }
    virtual void BuildPart3() { component3 = true; }
    virtual void BuildPart4() { component4 = true; }
    virtual ComplexProduct* GetProduct() const {return new ComplexProduct(component1,component2,component3,component4);}
};
class Director2 {
public:
    void construct(Builder* b) { b->BuildPart3(); b->BuildPart1(); b->BuildPart4(); b->BuildPart2(); }
};