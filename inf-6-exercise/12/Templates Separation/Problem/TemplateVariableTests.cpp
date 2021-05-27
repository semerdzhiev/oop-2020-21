#include "Variable.h"

#include <iostream>

int main()
{
	// грешка по време на компилация
	// не се открива дефиниция на конструктора Variable<int>(int const&)
	
	// такава не е генерирана, защото по време на компилацията 
	// на Variable.cpp файла, не е срещнат конкретния тип, който да замени Т

	Variable<int> intVar(2, "a");
	std::cout << intVar.value << std::endl;

	return 0;
}