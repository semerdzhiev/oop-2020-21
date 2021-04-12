#include <cstring>
#include <iostream>
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
 */

#include "UserVariable.h"
#include "VariableCollection.h"

void print(const VariableName &v) {
	v.print();
}

int main() {
	try {
		VariableCollection collection;

		char command[32];
		do {
			std::cin >> command;
			if (!strcmp(command, "declare")) {
				VariableName name = VariableName::read();
				collection.declareVariable(name);
			} else if (!strcmp(command, "assign")) {
				VariableName name = VariableName::read();
				int value;
				std::cin >> value;
				collection.assignVariable(name, value);
			} else if (!strcmp(command, "print")) {
				VariableName name = VariableName::read();
				collection.printVariable(name);
			} else if (!strcmp(command, "calc")) {
				// calc a + b
				// calc a - b
				VariableName left, right;
				left = VariableName::read();
				char op;
				std::cin >> op;
				right = VariableName::read();
				UserVariable res = collection.calc(left, right, op);
				res.printValue();
			}
		} while (strcmp(command, "quit") != 0);
	} catch (std::bad_alloc &ex) {
		std::cout << "Can't continue - no memory";
	}

	return 0;
}

