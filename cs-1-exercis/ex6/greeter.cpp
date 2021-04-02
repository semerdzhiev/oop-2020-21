#include <iostream>
#include <string>
#include "greeter.h" 

using namespace std;

// maybe move to stringutils.cpp
bool isEmpty(const char * str) {
	if (str == NULL) {
		return true;
	}

	while (*str) {
		if (*str != ' ') {
			return false;
		}
		str++;
	}
	return true;
}

void Greeter::sayHello(const char * name) {
	cout << generateHelloMessage(name) << endl;
}

string Greeter::generateHelloMessage(const char * name) {
	string realName = isEmpty(name) ? "World" : name;
	
	string result = "Hello ";
	result += realName;
	result += "!";
	return result;
}
