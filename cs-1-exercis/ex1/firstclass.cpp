#include <iostream>
using namespace std;

/*
class Greeter { // class named Greeter
	int n;

public:
	Greeter() { // constructor
		n = 0;
	}

	void sayHi(const char * name) {	//  method
		cout << "Hello " << name << "! ("  << ++n <<  ")" << endl;
	}
};
*/


// Class declaration
class Greeter { 
	int n;
public:
	Greeter(); // constructor
	void sayHi(const char * name);
};


// Definition of the methods
Greeter::Greeter() {
	n = 0;
}

void Greeter::sayHi(const char * name) {	//  method
	cout << "Hello " << name << "! ("  << ++n <<  ")" << endl;
}


int main() {
	Greeter g1; // g is instance of the Greeter class. g is an object.
	g1.sayHi("World");
	g1.sayHi("World");
	g1.sayHi("World");
	g1.sayHi("World");
	g1.sayHi("World");


	Greeter g2; // g is instance of the Greeter class. g is an object.
	g2.sayHi("Again");
	g1.sayHi("World");
	g2.sayHi("Again");
	g1.sayHi("World");
	g2.sayHi("Again");
	g1.sayHi("World");
	return 0;
}
