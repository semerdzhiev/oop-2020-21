#include "CStringFunctions.h"
#include "DEmployee.h"

#include <cstring>
#include <iostream>

DEmployee::DEmployee(const char* newName, const char* newPosition, double newSalary)
{
	createDynCopy(this->name, newName);
	createDynCopy(this->position, newPosition);

	this->setSalary(newSalary);
}

DEmployee::DEmployee(const DEmployee& other)
	: DEmployee(other.name, other.position, other.salary)
{}

DEmployee& DEmployee::operator=(const DEmployee& other)
{
	if (this != &other)
	{
		this->setName(other.name);
		this->setPosition(other.position);
		this->setSalary(other.salary);
	}
	
	return *this;
}

DEmployee::~DEmployee()
{
	// clear the dynamic memory used for the name and the position of the current object
	delete[] this->name;
	delete[] this->position;
}

const char* DEmployee::getName() const
{
	return this->name;
}

const char* DEmployee::getPosition() const
{
	return this->position;
}

double DEmployee::getSalary() const
{
	return this->salary;
}

void DEmployee::setName(const char* newName)
{
	delete[] this->name;
	createDynCopy(this->name, newName);
}

void DEmployee::setPosition(const char* newPosition)
{
	delete[] this->position;
	createDynCopy(this->position, newPosition);
}

void DEmployee::setSalary(double newSalary)
{
	if (newSalary >= 610 && newSalary <= 10000)
	{
		this->salary = newSalary;
	}
	else if (newSalary < 610)
	{
		this->salary = 610;
	}
	else
	{
		this->salary = 10000;
	}
}

void DEmployee::print() const
{
	std::cout << "Name: " << (this->name? this->name : "") << std::endl;
	std::cout << "Position: " << (this->position? this->position : "") << std::endl;
	std::cout << "Salary: " << this->salary << std::endl;
}