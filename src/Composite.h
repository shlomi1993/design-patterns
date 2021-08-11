//
// Created by Shlomi on 15/04/2021.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include "iostream"

// Composite is a structural DP that allows to create a dynamic hierarchy in a form of a tree where the leafs do the
// job and the composites have a list of childrens. This is a recursive DP.

// IMPORTANT NOTE: This implementation is not handling the enclosing circle problem.

using namespace std;

class Component { // e.g., "Music".
protected:
    Component *parent;  // To solve the enclosing circle problem.
public:
    virtual void operation() const =0;
    virtual void add(Component *c) =0;
    virtual void remove(Component *c) =0;
    virtual void setParent(Component *c) { parent = c; }
    virtual Component* getParent() const { return parent; }
    virtual string getDescription() =0;
    virtual bool IsComposite() const { return false; }
};

// A leaf have no childrens, and do the job.
class Leaf : public Component {  // e.g., "Song".
    string description;
public:
    Leaf(string d) : description(d) {}
    virtual void operation() const { cout << "leaf " + description + " doing operation" << endl; }
    virtual void add(Component *c) {}       // Not implemented by the leaves.
    virtual void remove(Component *c) {}    // Not implemented by the leaves.
    virtual string getDescription() { return description; }
};

// A composite have a list of other components which are composites or leaves.
class Composite : public Component {  // e.g., "Playlist".
private:
    string description;
protected:
    list<Component *> children;     // A composite have a list of other components.
public:
    Composite(string d) : description(d) {}
    virtual void operation() const { for (const Component *c : children) c->operation(); }
    virtual void add(Component *c) {
        children.push_back(c);
        c->setParent(this);
    }
    virtual void remove(Component *c) {
        children.remove(c);
        c->setParent(nullptr); }
    virtual string getDescription() { return description; }
    bool IsComposite() const { return true; }
};


// This DP isn't maintain O from SOLID because once you add somethng to the Coponent interface, you have to all methods
// to all kind of laeaves and composites. Also it isn't maintain I from SOLID because leafs have to implement unused
// interface methods.

// When using this DP, it is very important to handle the enclosing circle problem.
