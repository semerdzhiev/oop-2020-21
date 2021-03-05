#include "Employee.h"
#include "Utils.h"

#include <cstring>
#include <iomanip>
#include <iostream>

void readEmployee(Employee& employee)
{
	std::cout << "Enter the id of the employee: ";
	size_t id = readPositiveInteger();

	std::cout << "Enter the name of the employee: ";
	char name[nameMaxLength]{};
	readString(name, nameMaxLength);

	std::cout << "Enter the position of the employee: ";
	char position[positionMaxLength]{};
	readString(position, positionMaxLength);
	
	std::cout << "Work experience: ";
	unsigned workExperience = readPositiveInteger(40);

	std::cout << "Wage: ";
	double wage = readNonNegativeDouble();

	employee.id = id;
	strcpy_s(employee.name, nameMaxLength, name);
	employee.workExperience = workExperience;
	employee.wage = wage;
}

void printEmployee(const Employee& employee)
{
	std::cout << std::left << std::setw(5) << employee.id
			  << std::setw(20) << employee.name 
			  << "\tWork experience: " << std::right << std::setw(5) << employee.workExperience
			  << "\tWage: " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << employee.wage << std::endl;
}

