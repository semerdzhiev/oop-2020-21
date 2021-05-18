#include "Variable.h"

#include <iostream>

int main()
{
	Variable<int> intVar(2, "a");
	std::cout << intVar.value << std::endl;

	return 0;
}