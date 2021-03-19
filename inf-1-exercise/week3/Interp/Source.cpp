#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
/*
Constructor/Destructor (class/struct)

Входа винаги е коректен
Променливите са винаги целочислени
Имената на променливите са < 32
Броя променливи ще е < 200

declare size
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

typedef char VariableName[32];
const int maxCount = 200;
struct UserVariable {
	VariableName name;
	int value = 0;
	bool init = false;

	UserVariable() {}
	//UserVariable() = default;

	UserVariable(VariableName varName, int varValue, bool varInit)
		: value(varValue), init(varInit) {
		strcpy(name, varName);
	}
};

struct VariableCollection {
	UserVariable variables[maxCount];
	int variableCount = 0;

	void declareVariable(VariableName name) {
		strcpy(variables[variableCount].name, name);
		std::cout << "Declared variable " << variables[variableCount].name << std::endl;
		++variableCount;
	}
};

int findVariableIndex(UserVariable vars[], int variableCount, VariableName search) {

	for (int c = 0; c < variableCount; ++c) {
		if (strcmp(vars[c].name, search) == 0) {
			return c;
		}
	}
	return -1;
}



void assignVariable(UserVariable vars[], int &variableCount, VariableName name, int value) {
	const int index = findVariableIndex(vars, variableCount, name);
	vars[index].init = true;
	vars[index].value = value;
	std::cout << "Assigned variable " << name << " = " << value << std::endl;
}

void printVariable(UserVariable vars[], int &variableCount, VariableName name)
{
	const int index = findVariableIndex(vars, variableCount, name);
	if (vars[index].init) {
		std::cout << vars[index].value << std::endl;
	} else {
		std::cout << "Undefined variable " << name << std::endl;
	}
}

int main() {
	VariableCollection collection;

	// UserVariable variables[maxCount];
	//int variableValues[maxCount];
	//VariableName variableNames[maxCount];
	//bool initVariables[maxCount];

	//int variableCount = 0;

	char command[32];
	do {
		std::cin >> command;
		if (!strcmp(command, "declare")) {
			VariableName name;
			std::cin >> name;
			collection.declareVariable(name);
			// declareVariable(collection.variables, collection.variableCount, name);
		} else if (!strcmp(command, "assign")) {
			VariableName name;
			int value;
			std::cin >> name >> value;
			assignVariable(collection.variables, collection.variableCount, name, value);
		} else if (!strcmp(command, "print")) {
			VariableName name;
			std::cin >> name;
			printVariable(collection.variables, collection.variableCount, name);
		} else if (!strcmp(command, "calc")) {

		}
	} while (strcmp(command, "quit") != 0);

	return 0;
}

