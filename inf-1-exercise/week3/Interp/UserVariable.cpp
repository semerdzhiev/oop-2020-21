#include "UserVariable.h"

#include <iostream>

bool isSpace(char c) {
	return c == ' ' ||
		c == '\t' ||
		c == '\n';
}

VariableName VariableName::read() {
	VariableName name;
	int capacity = 4;
	char *myString = new char[capacity + 1];

	char current = std::cin.get();
	int size = 0;
	while (isSpace(current)) {
		current = std::cin.get();
	}
	while (!isSpace(current)) {
		if (size >= capacity) {
			capacity *= 2;
			char *copy = new char[capacity + 1];
			//for (int c = 0; c < initialSize; c++) {
			//	copy[c] = myString[c];
			//}
			memcpy(copy, myString, size);
			delete[] myString;
			myString = copy;
		}
		myString[size] = current;
		size++;
		current = std::cin.get();
	}
	myString[size] = '\0';

	name.data = myString;
	name.size = size;
	return name;
}


VariableName::VariableName() {
	data = new char[1];
	size = 0;
	data[0] = '\0';
}

VariableName::VariableName(const VariableName &other)
	: size(0), data(nullptr) {
	data = new char[other.size + 1];
	strcpy(data, other.data);
	size = other.size;
}

VariableName::~VariableName() {
	delete[] data;
}

VariableName &VariableName::operator=(const VariableName &right) {
	VariableName *s = this;
	if (this != &right) {
		char *newBuffer = new char[right.size + 1];
		delete[] data;
		data = newBuffer;
		strcpy(data, right.data);
		size = right.size;
	}
	return *this;
}

bool VariableName::operator==(const VariableName &other) const {
	return strcmp(data, other.data) == 0;
}

void VariableName::print() const {
	std::cout << data;
}

void UserVariable::printValue() const {
	if (init) {
		name.print();
		std::cout << " = " << value;
	} else {
		std::cout << "Variable ";
		name.print();
		std::cout << " is not initialized";
	}
	std::cout << std::endl;
}

void UserVariable::setName(const VariableName &newName) {
	name = newName;
}

void UserVariable::setValue(int newValue) {
	value = newValue;
	init = true;
}