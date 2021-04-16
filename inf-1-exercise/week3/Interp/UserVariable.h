#pragma once
#include <iostream>

const int maxCount = 200;

class VariableName {
public:
	VariableName();

	/*explicit*/ VariableName(const char *name);

	// copy constructor
	VariableName(const VariableName &other);

	// move constructor
	VariableName(VariableName &&other);

	// move op =
	VariableName &operator=(VariableName &&other);

	~VariableName();

	VariableName &operator=(const VariableName &right);

	bool operator==(const VariableName &other) const;

	void print() const;
	static VariableName read();
private:
	char *data;
	int size;
};

class UserVariable {
public:
	UserVariable() {}
	//UserVariable() = default;

	UserVariable(VariableName name, int varValue, bool varInit)
		: name(std::move(name)), data(varValue), init(varInit)
	{}

	void setName(const VariableName &name);

	UserVariable operator+(const UserVariable &right) const {
		UserVariable res;
		res.data = data + right.data;
		res.init = true;
		return res;
	}

	UserVariable operator-(const UserVariable &right) const {
		UserVariable res;
		res.data = data - right.data;
		res.init = true;
		return res;
	}

	UserVariable operator*(const UserVariable &right) const {
		UserVariable res;
		res.data = data * right.data;
		res.init = true;
		return res;
	}

	UserVariable operator/(const UserVariable &right) const {
		UserVariable res;
		res.data = data / right.data;
		res.init = true;
		return res;
	}

	void setValue(int value);

	void printValue() const;

	const VariableName &getName() const {
		return name;
	}

	const int &getValue() const {
		return data;
	}

	bool isInit() const {
		return init;
	}

private:
	VariableName name;
	int data = 0;
	bool init = false;
};
