#include "GoodbyePrinter.h"
#include "HelloPrinter.h"
#include <iostream>


void printGoodbye(char* name) {
	printHello(name);
	std::cout << "Goodbye " << name << std::endl;
}
