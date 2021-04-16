//
// Created by Shlomi on 15/04/2021.
//

#include "Singleton.h"

// A very important line!
Singleton* Singleton::singleton_ptr = nullptr;

// Static methods must be defined outside the class.
Singleton* Singleton::GetInstance() {
    // This is a safer way to create an instance. instance = new Singleton is
    // dangerous in case two instance threads wants to access at the same time.
    if (singleton_ptr == nullptr)
        singleton_ptr = new Singleton();
    return singleton_ptr;
}