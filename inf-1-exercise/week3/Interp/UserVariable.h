#pragma once

const int maxCount = 200;

class VariableName {
public:
	VariableName();

	VariableName(const VariableName &other);

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

	UserVariable(const VariableName &name, int varValue, bool varInit)
		: name(name), value(varValue), init(varInit)
	{}

	void setName(const VariableName &name);

	UserVariable operator+(const UserVariable &right) const {
		UserVariable res;
		res.value = value + right.value;
		res.init = true;
		return res;
	}

	UserVariable operator-(const UserVariable &right) const {
		UserVariable res;
		res.value = value - right.value;
		res.init = true;
		return res;
	}

	UserVariable operator*(const UserVariable &right) const {
		UserVariable res;
		res.value = value * right.value;
		res.init = true;
		return res;
	}

	UserVariable operator/(const UserVariable &right) const {
		UserVariable res;
		res.value = value / right.value;
		res.init = true;
		return res;
	}

	void setValue(int value);

	void printValue() const;

	const VariableName &getName() const {
		return name;
	}

private:
	VariableName name;
	int value = 0;
	bool init = false;
};
