#pragma once

#include "UserVariable.h"

class VariableCollection {
public:

	void declareVariable(const VariableName &name);

	void assignVariable(const VariableName &name, int value);

	void printVariable(const VariableName &name) const;

	UserVariable calc(const VariableName &left, const VariableName &right, char op);
private:
	int findVariableIndex(const VariableName &search) const;

	UserVariable variables[maxCount];
	int variableCount = 0;
};