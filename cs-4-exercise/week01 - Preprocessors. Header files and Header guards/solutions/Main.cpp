#include "DynArray.h"
#include <iostream>


int main() {

	DynArray dynArray = create();
	push_back(dynArray, 10);
	push_back(dynArray, 20);

	std::cout << get(dynArray, 1) << std::endl;

	pop_back(dynArray);

	std::cout << get(dynArray, 0) << std::endl;
	eraseDynMemory(dynArray);

	std::cout << get(dynArray, 0) << std::endl;



	return 0;
}