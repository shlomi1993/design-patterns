//
// Created by Shlomi on 16/04/21.
//

#include <iostream>

using namespace std;

// Interpreter is a behavioral DP that used to defines a grammatical representation for a language and provides an
// interpreter to deal with this grammar.

class AbstractExpression {
public:
    virtual void print() =0;  // Just for the exmple, not from the UML.
    virtual double evaluate() =0; // Sometimes named "interpret" in UMLs.
};

class TerminalExpression : public AbstractExpression {
public:
    virtual void print() =0;
    virtual double evaluate() =0;
    TerminalExpression() {}
};

class Number : public TerminalExpression {
    double sign; // 1 or -1. Can be bool as well.
    double value;
public:
    Number(double v) : value(v) { sign = v < 0 ? -1 : 1; }
    virtual void print() { cout << value; }
    virtual double evaluate() { return value; }
};

class Variable : public TerminalExpression {
    double sign; // 1 or -1. Can be bool as well.
    double value;
    char   param;
public:
    Variable(char p) : param(p) {}
    virtual void print() { cout << param; }
    virtual double evaluate() { try {return value;} catch (int x) { } }
    void assign(double v) { value = v; sign = v < 0 ? -1 : 1; }
};

class NonTerminalExpression : public AbstractExpression {
protected:
    AbstractExpression* a;
    AbstractExpression* b;
    NonTerminalExpression(AbstractExpression *a, AbstractExpression *b) : a(a), b(b) {}
    virtual void print() =0;
    virtual double evaluate() =0;
};

class Plus : public NonTerminalExpression {
public:
    Plus(AbstractExpression *a, AbstractExpression *b) : NonTerminalExpression(a, b) {}
    virtual void print() { cout << "("; a->print(); cout << " + "; b->print(); cout << ")"; }
    virtual double evaluate() { return a->evaluate() + b->evaluate(); }
};

class Minus : public NonTerminalExpression {
public:
    Minus(AbstractExpression *a, AbstractExpression *b) : NonTerminalExpression(a, b) {}
    virtual void print() { cout << "("; a->print(); cout << " - "; b->print(); cout << ")"; }
    virtual double evaluate() { return a->evaluate() - b->evaluate(); }
};
