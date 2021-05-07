#include "UserVariable.h"

#include <iostream>

bool isSpace(char c) {
	return c == ' ' ||
		c == '\t' ||
		c == '\n';
}

VariableName VariableName::read() {
	VariableName name;
	std::cin >> name;
	return name;
}

std::istream &operator>>(std::istream &inStream, VariableName &right) {
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

	delete[] right.data;
	right.data = myString;
	right.size = size;
	return inStream;
}

std::ostream &operator<<(std::ostream &outStream, const VariableName &name) {
	return outStream << name.getData();
}

bool operator==(const VariableName &left, const VariableName &right) {
	return strcmp(left.getData(), right.getData()) == 0;
}


VariableName::VariableName() {
	data = new char[1];
	size = 0;
	data[0] = '\0';
}

VariableName::VariableName(const char *name) {
	size = strlen(name);
	data = new char[size + 1];
	strcpy(data, name);
}

VariableName::VariableName(const VariableName &other)
	: size(0), data(nullptr) {
	data = new char[other.size + 1];
	strcpy(data, other.data);
	size = other.size;
}

VariableName::VariableName(VariableName &&other) : data(nullptr), size(0) {
	std::swap(size, other.size);
	std::swap(data, other.data);
}

VariableName &VariableName::operator=(VariableName &&other) {
	std::swap(size, other.size);
	std::swap(data, other.data);
	return *this;
}

VariableName::~VariableName() {
	delete[] data;
}

VariableName &VariableName::operator=(const VariableName &right) {
	if (this != &right) {
		char *newBuffer = new char[right.size + 1];
		delete[] data;
		data = newBuffer;
		strcpy(data, right.data);
		size = right.size;
	}
	return *this;
}


UserVariable::UserVariable(VariableName name, int varValue, bool varInit)
	: name(std::move(name)), data(varValue), init(varInit) {}

UserVariable UserVariable::operator+(const UserVariable &right) const {
	UserVariable res;
	res.data = data + right.data;
	res.init = true;
	return res;
}

UserVariable UserVariable::operator-(const UserVariable &right) const {
	UserVariable res;
	res.data = data - right.data;
	res.init = true;
	return res;
}

UserVariable UserVariable::operator*(const UserVariable &right) const {
	UserVariable res;
	res.data = data * right.data;
	res.init = true;
	return res;
}

UserVariable UserVariable::operator/(const UserVariable &right) const {
	UserVariable res;
	res.data = data / right.data;
	res.init = true;
	return res;
}

void UserVariable::setName(const VariableName &newName) {
	name = newName;
}

void UserVariable::setValue(int newValue) {
	data = newValue;
	init = true;
}

const VariableName &UserVariable::getName() const {
	return name;
}

const int &UserVariable::getValue() const {
	return data;
}

bool UserVariable::isInit() const {
	return init;
}

std::ostream &operator<<(std::ostream &outStream, const UserVariable &right) {
	if (right.isInit()) {
		return outStream << right.getName() << "=" << right.getValue();
	} else {
		return outStream << "Unininialized variable " << right.getName();
	}
}
