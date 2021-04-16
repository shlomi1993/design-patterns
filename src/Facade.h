//
// Created by Shlomi on 15/04/2021.
//

#include "iostream"

// Facade is a structural DP that provides a simplified interface to a library, a framework, or any other complex set of
// classes. It allows to hide inner structure from clients. All the clients (UI, Driver Code, remote clients) can't see
// the system works. Instead, they are cmmunicating with a class specifically designed to communicate with them - to
// recieve their input, pass it to the system, return the output to the client.
// The main goal of the facade is ENCAPSULATION and maintain Low coupling, High Cohesion.

using namespace std;

// Suppose our complex system consists of two subsystems.

class Subsystem1 {
public:
    string Operation1() const { return "Subsystem1: Ready!\n"; }
    // ...
    string OperationN() const { return "Subsystem1: Go!\n"; }
};

class Subsystem2 {
public:
    string Operation1() const { return "Subsystem2: Get ready!\n"; }
    // ...
    string OperationM() const { return "Subsystem2: Fire!\n"; }
    // Note that the different sub-systems might have similiar and different methods.
};

// The Facade class provides a simple interface to the complex logic of one or several subsystems. The Facade delegates
// the client requests to the appropriate objects within the subsystem. The Facade is also responsible for managing
// their lifecycle. All of this shields the client from the undesired complexity of the subsystem.

class Facade {
protected:
    Subsystem1 *system1;
    Subsystem2 *system2;
public:
    // In this case we will delegate the memory ownership to Facade Class.
    Facade(Subsystem1 *ss1, Subsystem2 *ss2) : system1(ss1), system2(ss2) {}
    ~Facade() { delete system1; delete system2; }
    // Facade's methods are convenient shortcuts to the sophisticated functionality of the subsystems. However, clients
    // get only to a fraction of a subsystem's capabilities.
    string start() {
        string result = "Facade initializes subsystems:\n";
        result += this->system1->Operation1();
        result += this->system2->Operation1();
        return result;
    }
    string work() {
        string result = "Facade orders subsystems to perform the action:\n";
        result += this->system1->OperationN();
        result += this->system2->OperationM();
        return result;
    }
};