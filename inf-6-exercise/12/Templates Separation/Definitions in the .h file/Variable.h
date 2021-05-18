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

template<typename T>
inline Variable<T>::Variable(const T& initialValue, const std::string& initialName)
	: value(initialValue), name(initialName)
{}

#endif // !VARIABLE_H




