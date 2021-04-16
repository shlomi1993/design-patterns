//
// Created by Shlomi on 16/04/2021.
//

#include <iostream>
#include "Factory.h"
#include "AbstractFactory.h"
#include "Prototype.h"
#include "Builder.h"
#include "Singleton.h"
#include "ClassAdapter.h"
#include "ObjectAdapter.h"
#include "Bridge.h"
#include "Composite.h"
#include "Decorator.h"
#include "Facade.h"
#include "Flyweight.h"
#include "Proxy.h"
#include "Command.h"
#include "Interpreter.h"
#include "Iterator.h"
#include "Observer.h"
#include "State.h"
#include "TemplateMethod.h"
#include "Strategy.h"

using namespace std;

void factory() {

	// Naive facotry driver.
	// Creator *conCreator1 = new ConcreteCreator1;
    // Creator *conCreator2 = new ConcreteCreator2;
    // cout << conCreator1->doTask() << endl;
    // cout << conCreator2->doTask() << endl;

	Creator* factory = new Creator();
    Product* product;
	product = factory->create("ConcreteProduct1");
    if (product) product->operation1(); else cout<<"not in the map"<<endl;
    product = factory->create("ConcreteProduct2");
    if (product) product->operation2(); else cout<<"not in the map"<<endl;
    product = factory->create("ConcreteProduct5");
    if (product) product->operation1(); else cout<<"not in the map"<<endl;

}

void abstract_factory() {
    AbstractFactory* factory;
	char type;
	cout << "Enter type (1 or 2): ";
	cin >> type;
	switch (type) {
		case '1': factory = new ConcreteFactory1(); break;
		case '2': factory = new ConcreteFactory2(); break;
		default : return;
	}
	AbstractProductA *A = factory->CreateProductA();
    AbstractProductB *B = factory->CreateProductB();
    cout << "A type: " << A->UsefulFunctionA() << endl;
    cout << "B type: " << B->UsefulFunctionB() << endl;
}

void prototype() {
	char choose;
    Prototype* prototype;
	cout << "Enter concrete prototype ('1' or '2'): ";
	cin >> choose;
	switch (choose) {
		case '1': prototype = new ConcretePrototype1(1, 2, 3);	break;
		case '2': prototype = new ConcretePrototype2(4, 5);		break;
		default : ;
	}
    Prototype* copy = prototype->clone();
    cout << "prototype address: " << &prototype << ", ";
    prototype->print();
    cout << "copy address:      " << &copy << ", ";
    copy->print();
}

void builder() {

	// Option 1: No UML, Yes chain construction.
	ComplexBuilder cb;
	Director d(cb);
	ComplexProduct* cp = d.construct(); // the director determine the build order.
	cp->print();
	delete cp;

	// Option 2: Yes UML, No chain construction.
	Builder *b = new ConcreteBuilder();
	Director2* d2 = new Director2();
	d2->construct(b);
	b->GetProduct()->print();
	delete d2;
}

void singleton() {
    Singleton* stp1 = Singleton::GetInstance();	// Static access.
    Singleton* stp2 = Singleton::GetInstance();
	cout << "spt1 points to " << stp1 << endl;
    cout << "stp2 points to " << stp2 << endl;
}

void class_adapter() {
	Target* target = new Adapter();
    target->request();
}

void object_adapter() {
	char input;
    objTarget* target;
	cout << "Choose adaptee (1 or 2)" << endl;;
	cin >> input;
	switch (input) {
		case '1':
			target = new objAdapter(new ConcreteAdaptee1());
			break;
		case '2':
			target = new objAdapter(new ConcreteAdaptee2());
			break;
		default: ;
	}
    target->request();
}

void bridge() {
	Abstraction* a1 = new RefinedAbstraction1(new ConcreteImplementor1());
    a1->operation();
	Abstraction* a2 = new RefinedAbstraction2(new ConcreteImplementor1());
    a2->operation();
	Abstraction* a3 = new RefinedAbstraction1(new ConcreteImplementor2());
    a3->operation();
	Abstraction* a4 = new RefinedAbstraction2(new ConcreteImplementor2());
    a4->operation();
}

void composite() {
	Component *root = new Composite("Root");
    Component *l1 = new Leaf("L1");
    Component *l2 = new Leaf("L2");
    Component *subtree = new Composite("Sub-tree");
    Component *l3 = new Leaf("L3");
    Component *l4 = new Leaf("L4");

    root->add(l1);
    root->add(l2);
    root->add(subtree);
    subtree->add(l3);
    subtree->add(l4);

	cout << "The whole tree: " << endl;
    root->operation();
	cout << endl;

	cout << "try to remove L3 from Root: " << endl;
	root->remove(l3);
	root->operation();
	cout << endl;

	cout << "Remove L2 from Root: " << endl;
	root->remove(l2);
	root->operation();
	cout << endl;

	cout << "Return L2 to Root: " << endl;
	root->add(l2);
	root->operation();
	cout << endl;

	cout << "Try to add Root to Subtree: " << endl;
	subtree->add(root);
	root->operation();
	cout << endl;

	cout << "Remove Subtree (L3, L4) from the Root: " << endl;
	root->remove(subtree);
	root->operation();
	cout << endl;

	cout << "Try to add Root to L1: " << endl;
	l1->add(root);	// add is an empty function for leaf.
	root->operation();
	cout << endl;

}

void decorator() {
	AbstractComponent* ac1 = new ConcreteComponentDecoratorC(new ConcreteComponentDecoratorA(new ConcreteComponentA()));
    cout << "Abstract Component 1: " << ac1->getDescription() << " = " << ac1->getNumericState() << endl;
    AbstractComponent* ac2 = new ConcreteComponentDecoratorB(new ConcreteComponentB());
    cout << "Abstract Component 2: " << ac2->getDescription() << " = " << ac2->getNumericState() << endl;
}

void facade() {

    Subsystem1 *subsystem1 = new Subsystem1;
    Subsystem2 *subsystem2 = new Subsystem2;
    Facade *facade = new Facade(subsystem1, subsystem2);
    // The client have access only to some facades.
	
	cout << facade->start();
    cout << "First operation is done." << endl;
    cout << facade->work();
    cout << "Second operation is done." << endl;
    
	delete facade;
	
}

void flyweight() {
	
	// Creates a matrix (let's say it is a game map).
	Flyweight *matrix[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = nullptr;
        }
    }

	// Setup flyweights (game units).
    FlyweightFactory *fw1 = new FW1_Factory();		// Suppose fw1 is a soldier.
    FlyweightFactory *fw2 = new FW2_Factory();		// Suppose fw2 is a tank.
    matrix[1][1] = fw2->getFlyweight(100);
    matrix[2][2] = fw2->getFlyweight(100);
    matrix[0][1] = fw1->getFlyweight(50);
    matrix[1][3] = fw1->getFlyweight(50);
    matrix[3][0] = fw1->getFlyweight(50);

	// Print matrix data.
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j])
                matrix[i][j]->print(i, j);
        }
    }

	cout << endl;

	// Print matrix data after hit.
    matrix[1][1] = fw2->getFlyweight(7);
	cout << "fw2 (a tank) was hit!" << endl;
	matrix[1][1]->print(1, 1);

    cout << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j])
                matrix[i][j]->print(i, j);
        }
    }
}

void proxy() {
	string input;
	do {
		Internet *web = new Proxy;
		cout << "Enter a URL:\n(hint: tiktok.com was access modified by proxy)" << endl;
		cin >> input;
		web->request(input);
		cout << endl;
	} while (input != "exit");
}

void command() {
    Invoker invoker("Moshe");
    Reciever reciever(&invoker);		// The client holds only instance of the reciever. Note the "&".
    reciever.executeCommand1();
    reciever.executeCommand2();
}

void interpreter() {
	AbstractExpression* expression = new Plus((new Minus(new Number(7), new Number(2))), new Number(6));
    expression->print(); cout << " = " << expression->evaluate() << endl;
}

void my_iterator() {
	cout << "Int test" << endl;
    Container<int> c;
    for (int i = 1; i < 15; i += 2) c.add(i);
    Iterator<int, Container<int>> *it = c.CreateIterator();
    for (it->getFirst(); !it->hasMore(); it->getNext()) cout << *it->getCurrent() << endl;

    cout << "Data test (Data is a custom class/type)" << endl;
    Container<Data> d;
    Data u(100), v(200), w(300);
    d.add(u); d.add(v); d.add(w);
    Iterator<Data, Container<Data>> *dit = d.CreateIterator();
    for (dit->getFirst(); !dit->hasMore(); dit->getNext()) cout << dit->getCurrent()->getData() << endl;
}

void observer() {
	
	cout << "Create ConcreteSubject." << endl;
	ConcreteSubject cs;

	cout << "Set ConcreteSubject's state to \"State 1\"." << endl;
	cs.setState("State 1");

	cout << "Create a ConcreteObserver which observe (listen to) ConcreteSubject." << endl;
	ConcreteObserver co(&cs);

	cout << "Change ConcreteSubject's state to \"State 2\"." << endl;
	cs.setState("State 2");

	cout << "END" << endl;

}

void state() {
    Context c1(new Walker);		// Context's CTOR does: Context(State *s) : state(s) { s->Handle(); }
    Context c2(new Driver);
    Context c3(new Pilot);
}

void template_method() {
	cout << "Template Method + ConcreteClass1:\n";
    ConcreteClass1 *cc1 = new ConcreteClass1;
    ClientCode(cc1);
    cout << "\n";
    cout << "Template Method + ConcreteClass2:\n";
    ConcreteClass2 *cc2 = new ConcreteClass2;
    ClientCode(cc2);
	cout << "\n";
}

void strategy() {

	StrategyContext *context = new StrategyContext(new ConcreteStrategyA);
    cout << "Client: Strategy is set to normal sorting.\n";
    
	context->DoContextLogic();
    cout << "\n";
	
	context->setStrategy(new ConcreteStrategyB);
    cout << "Client: Strategy is set to reverse sorting.\n";

    context->DoContextLogic();
	cout << endl << "DONE" << endl;
}

int main(int argc, char *argv[]){

	if (argc != 2) { return -1; }
	
	switch (stoi(argv[1])) {

		// Creational Design Pattens
		case 1 : factory();				break;
		case 2 : abstract_factory();	break;
		case 3 : prototype();			break;
		case 4 : builder();				break;
		case 5 : singleton();			break;

		// Structural Design Pattens
		case 6 : class_adapter();		break;
		case 7 : object_adapter();		break;
		case 8 : bridge();				break;
		case 9 : composite();			break;
		case 10: decorator();			break;		// Need to solve enclosing circuit.
		case 11: facade();				break;
		case 12: flyweight();			break;
		case 13: proxy();				break;
		
		// Behavioural Design Patterns
		case 14: command();				break;
		case 15: interpreter();			break;
		case 16: my_iterator();			break;
		case 17: observer();			break;
		case 18: state();				break;
		case 19: template_method();		break;
		case 20: strategy();			break;

		default:;

	}

}


