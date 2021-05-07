#pragma once
#include <iostream>

const int maxCount = 200;

class VariableName {
public:
	VariableName();

	/*explicit*/ VariableName(const char *name);

	//operator const char *() const {
	//	return getData();
	//}

	// copy constructor
	VariableName(const VariableName &other);

	// move constructor
	VariableName(VariableName &&other);

	// move op =
	VariableName &operator=(VariableName &&other);

	~VariableName();

	VariableName &operator=(const VariableName &right);

	static VariableName read();

	// friend bool operator==(const VariableName &left, const VariableName &right);

	const char *getData() const {
		return data;
	}

	friend std::istream &operator>>(std::istream &inStream, VariableName &right);
private:
	char *data;
	int size;
};

std::istream &operator>>(std::istream &inStream, VariableName &right);

std::ostream &operator<<(std::ostream &outStream, const VariableName &name);

bool operator==(const VariableName &left, const VariableName &right);

class UserVariable {
public:
	UserVariable() {}
	//UserVariable() = default;

	const VariableName &getName() const;

	UserVariable(VariableName name, int varValue, bool varInit);

	void setName(const VariableName &name);

	UserVariable operator+(const UserVariable &right) const;

	UserVariable operator-(const UserVariable &right) const;

	UserVariable operator*(const UserVariable &right) const;

	UserVariable operator/(const UserVariable &right) const;

	void setValue(int value);

	const int &getValue() const;

	bool isInit() const;

	explicit operator bool () const {
		return init;
	}

	//operator const VariableName &() const {
	//	return name;
	//}

private:
	VariableName name;
	int data = 0;
	bool init = false;
};

std::ostream &operator<<(std::ostream &outStream, const UserVariable &right);
