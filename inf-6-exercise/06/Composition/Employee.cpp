#include <iostream>
#include <cstring>

#include "Date.h"
#include "Employee.h"

Employee::Employee(const char* name, const char* position, double salary, const Date& specifiedDate)
	// : hiredOn(specifiedDate)
	// use the initializer list to initialize the object directly using the copy contructor of class Date
{
	this->setName(name);
	this->setPosition(position);
	this->setSalary(salary);

	// assignment operator, the date has been initialized with the default constructor of the class
	// use the initializer list of the constructor instead
	this->hiredOn = specifiedDate;
}

void Employee::setName(const char* newName)
{
	if (newName == nullptr || strlen(newName) >= 20)
		return;

	strcpy_s(this->name, 20, newName);
}

void Employee::setPosition(const char* newPosition)
{
	if (newPosition == nullptr || strlen(newPosition) >= 20)
		return;

	strcpy_s(this->position, 20, newPosition);
}

void Employee::setSalary(double newSalary)
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

void Employee::setHiredOn(const Date& date)
{
	this->hiredOn = date;
}

void Employee::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Position: " << this->position << std::endl;
	std::cout << "Salary: " << this->salary << std::endl;

	std::cout << "Hired on: "; this->hiredOn.print();
}

double Employee::getSalary() const
{
	return this->salary;
}

const char* Employee::getName() const
{
	return this->name;
}

const char* Employee::getPosition() const
{
	return this->position;
}

Date Employee::getHiredOn() const
{
	return this->hiredOn;
}