#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

template <typename T>
struct Variable
{
	T value;
	std::string name;

	Variable(const T& initialValue, const std::string& intialName);
};

#include "Variable.inl"

#endif // !VARIABLE_H




