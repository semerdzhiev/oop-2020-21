#include <cstring>
#include <iostream>
/*
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

struct Variable {
	VariableName name;
	int value;
	bool init;
};

int findVariableIndex(VariableName names[], int variableCount, VariableName search){
	for (int c = 0; c < variableCount; ++c) {
		if (strcmp(names[c], search) == 0) {
			return c;
		}
	}
	return -1;
}

void declareVariable(bool initVariables[], VariableName variableNames[], int &variableCount, VariableName name) {

	//strcpy(variableNames[variableCount], name);
	int c = 0;
	for (; name[c] != '\0'; c++) {
		variableNames[variableCount][c] = name[c];
	}
	variableNames[variableCount][c] = '\0';

	initVariables[variableCount] = false;
	std::cout << "Declared variable " << variableNames[variableCount] << std::endl;
	++variableCount;
}

void assignVariable(VariableName variableNames[], int variableValues[],
	bool initVariables[], int &variableCount, VariableName name, int value)
{
	const int index = findVariableIndex(variableNames, variableCount, name);
	initVariables[index] = true;
	variableValues[index] = value;
	std::cout << "Assigned variable " << name << " = " << value << std::endl;
}

void printVariable(VariableName variableNames[], int variableValues[],
	bool initVariables[], int &variableCount, VariableName name)
{
	const int index = findVariableIndex(variableNames, variableCount, name);
	if (initVariables[index]) {
		std::cout << variableValues[index] << std::endl;
	} else {
		std::cout << "Undefined variable " << name << std::endl;
	}
}

int main() {
	// Variable variables[maxCount];
	int variableValues[maxCount];
	VariableName variableNames[maxCount];
	bool initVariables[maxCount];

	int variableCount = 0;

	char command[32];
	do {
		std::cin >> command;
		if (!strcmp(command, "declare")) {
			VariableName name;
			std::cin >> name;
			declareVariable(initVariables, variableNames, variableCount, name);
		} else if (!strcmp(command, "assign")) {
			VariableName name;
			int value;
			std::cin >> name >> value;
			assignVariable(variableNames, variableValues, initVariables, variableCount, name, value);
		} else if (!strcmp(command, "print")) {
			VariableName name;
			std::cin >> name;
			printVariable(variableNames, variableValues, initVariables, variableCount, name);
		} else if (!strcmp(command, "calc")) {

		}
	} while (strcmp(command, "quit") != 0);

	return 0;
}

