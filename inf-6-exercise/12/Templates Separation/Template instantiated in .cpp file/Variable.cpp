#include "Variable.h"

template<typename T>
Variable<T>::Variable(const T& initialValue, const std::string& initialName)
	: value(initialValue), name(initialName)
{}

// тук ни е нужен единствено конкретният тип, 
// за да може да се създаде клас по шаблона...

template struct Variable<int>;
template struct Variable<double>;

// но можем ли да изброим всички възможни типове,
// с които би могъл да се използва шаблонът?