//
// Created by Shlomi on 16/04/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Flyweight is a structural DP that allows to fit a large amount of objects into a small amount of RAM by sharing
// common parts of key between multiple objects instead of keeping all of the data in each object.

class Flyweight { // Flyweight interface.
protected:
    int key;
public:
    Flyweight() { key = 0; }
    void setKey(int k) { if (key != k) key = k; }
    int getKey() const { return key; }
    virtual void print(int i, int j) =0;    // Can be other common operation.
};

class ConcreteFW1 : public Flyweight {      // let's say a soldier.
public:
    ConcreteFW1(int k) { key = k; }
    virtual void print(int i, int j) {
        cout << "ConcreteFW1 " << this << " is at [" << i << ", " << j << "] with key = " << key << endl;
    }
};

class ConcreteFW2 : public Flyweight {      // let's say a tank.
public:
    ConcreteFW2(int k) { key = k; }
    virtual void print(int i, int j) {
        cout << "ConcreteFW2 " << this << " is at [" << i << ", " << j << "] with key = " << key << endl;
    }
};

class FlyweightFactory {    // Each Flyweight (e.g., each unit type) should have its own factory.
protected:
    vector<Flyweight *> fws;
    virtual Flyweight *newFlyweight(int k) =0;
public:
    Flyweight * getFlyweight(int k) {

        int i;
        int size = fws.size();
        
        // if (flyweight[key] exists):
        for (i = 0; i < size; i++) {
            if (fws.at(i)->getKey() == k)
                return fws.at(i);
        }

        // else:
        fws.push_back(newFlyweight(k));
        return fws.at(i);

    }
};

class FW1_Factory : public FlyweightFactory {
    virtual Flyweight *newFlyweight(int k) { return new ConcreteFW1(k); }
};

class FW2_Factory : public FlyweightFactory {
    virtual Flyweight *newFlyweight(int k) { return new ConcreteFW2(k); }
};