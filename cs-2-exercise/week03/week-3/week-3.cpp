#include <iostream>
#include "Stack.h"

int main() {
	Stack a;
	a.push(5);
	a.push(4);
	std::cout << a.getSize() << std::endl;;
	std::cout << a.top() << std::endl;
	a.pop();
	std::cout << a.top() << std::endl;
	return 0;
}