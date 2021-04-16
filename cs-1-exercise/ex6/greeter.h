#ifndef GREETER_H
#define GREETER_H

#include <string>
using namespace std;

// maybe move to stringutils.cpp
bool isEmpty(const char * str);

class Greeter {
public:
	void sayHello(const char * name);
	string generateHelloMessage(const char * name);
};

#endif