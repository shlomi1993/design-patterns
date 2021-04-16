//
// Created by Shlomi on 16/04/2021.
//

#include "iostream"

// Proxy is a structural DP that allows to provide a substitute or placeholder for another object. A proxy controls
// access to the original object, allowing to perform something either before or after the request gets through to the 
// original object.

using namespace std;

class Internet {                        // "Subject" in the UML.
public:
    virtual void request(string host) = 0;
};

class RealInternet : public Internet {  // "RealSubject" in the UML.
public:
    virtual void request(string host) { cout << "Connecting to " + host << endl; }
};

class Proxy : public Internet {         // "Proxy" in the UML.
private:
    Internet *real_internet;            // "realSubject" in the UML.
public:
    Proxy() : real_internet(new RealInternet) {}
    virtual void request(string host) {
        if (host == "tiktok.com") cout << "This site is banned!" << endl;
        else this->real_internet->request(host);
    }
};
