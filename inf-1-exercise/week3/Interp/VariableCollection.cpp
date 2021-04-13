#include "VariableCollection.h"

#include <iostream>

void VariableCollection::declareVariable(const VariableName &name) {
	variables[variableCount].setName(name);
	std::cout << "Declared variable ";
	variables[variableCount].getName().print();
	std::cout << std::endl;
	++variableCount;
}

int VariableCollection::findVariableIndex(const VariableName &search) const {
	for (int c = 0; c < variableCount; ++c) {
		if (variables[c].getName() == search) {
			return c;
		}
	}
	return -1;
}

void VariableCollection::assignVariable(const VariableName &name, int value) {
	const int index = findVariableIndex(name);
	variables[index].setValue(value);
	variables[index].printValue();
}

void VariableCollection::printVariable(const VariableName &name) const {
	const int index = findVariableIndex(name);
	variables[index].printValue();
}

UserVariable VariableCollection::calc(const VariableName &left, const VariableName &right, char op) {
	UserVariable result;
	const int leftIdx = findVariableIndex(left);
	const int rightIdx = findVariableIndex(right);

	// TODO:
	// result.setName("-temporary");

	switch (op) {
	case '+':
		result = variables[leftIdx] + variables[rightIdx];
		break;
	case '-':
		result = variables[leftIdx] - variables[rightIdx];
		break;
	case '*':
		result = variables[leftIdx] * variables[rightIdx];
		break;
	case '/':
		result = variables[leftIdx] / variables[rightIdx];
		break;
	}
	return result;
}