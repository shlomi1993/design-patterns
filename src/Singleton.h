//
// Created by Shlomi on 15/04/2021.
//

#include "iostream"

using namespace std;

// Singleton is a creational design pattern, which ensures that only one instance of singleton-object 
// exists (in the memory) and provides a single point of access to it for any other code.

class Singleton {

// The Singleton's constructor should be private to prevent direct construction calls with the `new` operator.
private:
    Singleton() {}            // Private constructor.
    static Singleton *singleton_ptr;            // Static private pointer to instance.

public:
    Singleton(Singleton &other) = delete;       // Singletons should not be cloneable.
    void operator=(const Singleton &) = delete; // Singletons should not be assignable.
    static Singleton* GetInstance();    // "Modified" instance creation method. MUST be implemented in the cpp.
    void SomeBusinessLogic() {}                 // Business logic.
};