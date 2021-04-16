//
// Created by Shlomi on 16/04/21.
//

#include <iostream>
#include <cstring>

using namespace std;

// Command is a behavioral DP that turns a request into a stand-alone object that contains all information about the
// request. This transformation lets you parameterize methods with different requests, delay or queue a request’s
// execution, and support undoable operation.

class Invoker {
    string description;
public:
    Invoker(string d) : description(d) {}
    void operation1() { cout << description + " doing operation1" << endl; }
    void operation2() { cout << description + " doing operation2" << endl; }
    string getDescription() { return description; }
};

class Command {

public:
    virtual void execute() =0;
};

class ConcreteCommand1 : public Command {
    Invoker * inv;
public:
    ConcreteCommand1(Invoker *inv) : inv(inv) {};
    void execute() { cout << inv->getDescription() << " execute command 1" << endl; }
};

class ConcreteCommand2 : public Command {
    Invoker * inv;
public:
    ConcreteCommand2(Invoker *inv) : inv(inv) {};
    void execute() { cout << inv->getDescription() << " execute command 2" << endl; }
};

class Reciever {
    Command ** commands;
public:
    Reciever(Invoker *inv) {    // E.g., Reciever=Parent, Invoker=Child.
        commands = new Command *[2] { new ConcreteCommand1(inv), new ConcreteCommand2(inv)};
    }
    void executeCommand1() { commands[0]->execute(); }
    void executeCommand2() { commands[1]->execute(); }
    // Now the commands are objects that can be used as OOP.
};