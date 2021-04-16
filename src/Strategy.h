//
// Created by Shlomi on 16/04/2021.
//

#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

// Strategy is a behavioral DP that allows to define a family of algorithms, put each of them into a separate class,
// and make their objects interchangeable.

class Strategy {
public:
    virtual string DoAlgorithm(const vector<string> &data) const =0;    // Named "AlgorithemInterface" in the UML.
};

// The Context defines the interface of interest to clients.
class StrategyContext {
    Strategy *strategy;
public:
    // Usually, the Context accepts a strategy through the constructor, but also provides a setter.
    StrategyContext(Strategy *strategy = nullptr) : strategy(strategy) {}
    void setStrategy(Strategy *newStrategy) { strategy = newStrategy; }
    
    // // The Context delegates some work to the Strategy object instead of implementing multiple algorithms on its own.
    void DoContextLogic() const {   // Named "ContextInterface" in the UML.
        string result = this->strategy->DoAlgorithm(vector<string>{"a", "e", "c", "b", "d"});
        cout << result << "\n";
    }
};

class ConcreteStrategyA : public Strategy {
public:
    virtual string DoAlgorithm(const vector<string> &data) const {
        string result;
        for_each (begin(data), end(data), [&result](const string &letter) { result += letter; });
        sort(begin(result), end(result));
        return result;
    }
};

class ConcreteStrategyB : public Strategy {
    virtual string DoAlgorithm(const vector<string> &data) const {
        string result;
        for_each (begin(data), end(data), [&result](const string &letter) { result += letter; });
        std::sort(std::begin(result), std::end(result));
        int limit = result.size() / 2;
        for (int i = 0; i < limit; i++) { swap(result[i], result[result.size() - i - 1]); }
        return result;
    }
};