#include "Date.h"
#include "Employee.h"

#include <iostream>

// Scope of the objects
void functionWithArgumentPassedByValue(Date date)
{
	std::cout << "functionWithArgumentPassedByValue()" << std::endl; 
}

void functionWithArgumentPassedByReference(const Date& date)
{
	std::cout << "functionWithArgumentPassedByReference()" << std::endl;
}

Date functionThatReturnsDate()
{
	Date result{ 1, 1, 2021 };
	return result;
}

int main()
{
	Date today{ 1, 4, 2021 };

	//{
		//Date copy = today;
		//
		//std::cout << "Copy: ";
		//copy.print();
	//}
		
	// std::cout << "After the inner section ... " << std::endl;

	//functionWithArgumentPassedByValue(today);
	//functionWithArgumentPassedByReference(today);

	//functionThatReturnsDate();

	Employee me{ "Me", "Teacher", 1300, today };

	return 0;
}