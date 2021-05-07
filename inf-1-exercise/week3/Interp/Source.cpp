#include <cstring>
#include <iostream>
#include <cassert>
/*
move

Входа винаги е коректен
Променливите са винаги целочислени
// fixed: Имената на променливите са < 32
Броя променливи ще е < 200

declare size_Sizeasdfsfgdhfhdfhgfdhsasdfsdafsdfasdfadgfdy464u
declare a

print size -> "Undefined variable size"

assign size 15
assign a 11

print size -> 15
quit

calc a + b
calc a * b
calc a / b
calc size - b
calc size % size

declare result
calc_var result a + b
 */

#include "UserVariable.h"
#include "VariableCollection.h"


int main() {
	try {
		VariableCollection collection;

		char command[32];
		do {
			std::cin >> command;
			if (!strcmp(command, "declare")) {
				VariableName name;
				std::cin >> name;
				collection.declareVariable(name);
			} else if (!strcmp(command, "assign")) {
				VariableName name;
				int value;
				std::cin >> name >> value;
				collection.assignVariable(name, value);
			} else if (!strcmp(command, "print")) {
				VariableName name;
				std::cin >> name;
				collection.printVariable(name);
			} else if (!strcmp(command, "calc")) {
				// calc a + b
				// calc a - b
				VariableName left, right;
				char op;
				std::cin >> left >> op >> right;
				UserVariable res = collection.calc(left, right, op);
				std::cout << res;
			} else if (!strcmp(command, "calc_var")) {
				// calc_var result left + right
				VariableName left, right, result;
				char op;
				std::cin >> result >> left >> op >> right;
				UserVariable value = collection.calc(left, right, op);
				collection.assignVariable(result, value.getValue());
			}
		} while (strcmp(command, "quit") != 0);
	} catch (std::bad_alloc &ex) {
		std::cout << "Can't continue - no memory";
	}

	return 0;
}

