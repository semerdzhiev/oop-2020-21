#include "Company.h"

#include <cstring>
#include <iostream>

Company::Company(const char* theName) : countEmployees(0)
{
	/*if (theName)
	{
		strcpy_s(this->name, 20, theName);
	}*/

	setName(theName);
}

const char* Company::getName() const
{
	return this->name;
}

void Company::setName(const char* newName)
{
	if (newName && strlen(newName) < 20)
	{
		strcpy_s(this->name, 20, newName);
	}
}

size_t Company::getCountEmployees() const
{
	return this->countEmployees;
}

bool Company::hireEmployee(const Employee& newEmployee)
{
	if (this->countEmployees < 20)
	{
		this->employees[this->countEmployees] = newEmployee;
		++this->countEmployees;

		return true;
	}

	return false;
}

bool Company::fireEmployee(size_t id)
{
	for (size_t index = 0; index < this->countEmployees; ++index)
	{
		if (this->employees[index].getID() == id)
		{
			for (size_t j = index; j < this->countEmployees - 1; ++j)
			{
				this->employees[j] = this->employees[j + 1];
			}

			-- this->countEmployees;
			return true;
		}
	}

	return false;
}

double Company::findSalaryExpenses() const
{
	double totalExpences = 0.0;

	size_t workDays = 20;
	for (size_t index = 0; index < this->countEmployees; ++index)
	{
		totalExpences += workDays * this->employees[index].getWage();
	}

	return totalExpences;
}

void Company::showInfo() const
{
	std::cout << "Company name: " << this->name << std::endl;
	
	std::cout << "Employees: " << this->countEmployees << std::endl;
	for (size_t index = 0; index < this->countEmployees; ++index)
	{
		this->employees[index].showInfo();
	}
}