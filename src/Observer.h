//
// Created by Shlomi on 16/04/2021.
//

// Observer is a behavioral DP that allows to define a subscription mechanism to notify multiple objects about any
// events that happen to the object they’re observing (or listening to).

#include <iostream>
#include <list>
#include <string>

using namespace std;

class Subject;   // Only decleration.

class Observer {
public:
    virtual void update(Subject& subject) =0;
};

class Subject {     // Sometimes named "Observable" in the UMLs.
    list<Observer *> observers;
public:
    void attach(Observer& o) { observers.push_back(&o); }
    void detach(Observer& o) { observers.remove(&o); }
    void notify() { for (auto & o : observers) o->update(*this); }
};

// The Subject owns some important state and notifies observers when the state changes.
// Multiple ConcreteSubjects allowed.
class ConcreteSubject : public Subject {    // also ConcreteObservable.
    string subjectState;
public:
    string getState() { return subjectState; }
    void setState(string newState) { subjectState = newState; notify(); }
};

// The Observer uses update method to pull updates from the osubject if occurred there are any.
// Multiple ConcreteObserver allowed.
class ConcreteObserver : public Observer {
private:
    string objectState;
    ConcreteSubject *subject;
public:
    ConcreteObserver(ConcreteSubject *cs) : subject(cs) { cs->attach(*this); }
    virtual void update(Subject& s) { objectState = subject->getState(); cout << "Observer Updated!" << endl; }
};