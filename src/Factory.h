//
// Created by Shlomi on 15/04/2021.
//

#include "iostream"
#include <map>
#include <functional>
#include "unistd.h"

using namespace std;

// Factory method is a creational design pattern which solves the problem of // creating product objects without
// specifying their concrete classes.


class Product {
protected:
    string description;
public:
    virtual void operation1() const = 0;
    virtual void operation2() const = 0;
    virtual string getType() { return description; }
};

class ConcreteProduct1 : public Product {
public:
    ConcreteProduct1() { this->description = "ConcreteProduct1"; }
    virtual void operation1() const { cout << "CP1-operation1" << endl; }
    virtual void operation2() const { cout << "CP1-operation2" << endl; }
};

class ConcreteProduct2 : public Product {
public:
    ConcreteProduct2() { this->description = "ConcreteProduct2"; }
    virtual void operation1() const { cout << "CP2-operation1" << endl; }
    virtual void operation2() const { cout << "CP2-operation2" << endl; }
};

class ConcreteProduct3 : public Product {
public:
    ConcreteProduct3() { this->description = "ConcreteProduct3"; }
    virtual void operation1() const { cout << "CP3-operation1" << endl; }
    virtual void operation2() const { cout << "CP3-operation2" << endl; }
};


// Naive creators:
// class Creator {
// public:
//     virtual Product* FactoryMethod() const = 0;
//     string doTask() const { // Named "AnOperation" in the UML.
//             Product* p = this->FactoryMethod();
//             cout << p->getType() <<": " << p->operation1() << " and " << p->operation2() << endl;
//         return "done!";
//     }
// };
// class ConcreteCreator1 : public Creator {
// public:
//     virtual Product* FactoryMethod() const { return new ConcreteProduct1(); }
// };
// class ConcreteCreator2 : public Creator {
// public:
//     virtual Product* FactoryMethod() const { return new ConcreteProduct2(); }
// };

// Using hashmap for better performance and less code:

class Creator {
    map<string, function<Product*()>> dictionary;
public:
    Creator() {
        dictionary.insert({"ConcreteProduct1", []() { return (Product *) new ConcreteProduct1(); }});
        dictionary.insert({"ConcreteProduct2", []() { return (Product *) new ConcreteProduct2(); }});
        dictionary.insert({"ConcreteProduct3", []() { return (Product *) new ConcreteProduct3(); }});
    }
    Product *create(const string& key) {
        if (dictionary.find(key) != dictionary.end())
            return dictionary.at(key)();
        return nullptr;
    }
};