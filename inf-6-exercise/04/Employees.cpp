#include "Employee.h"

#include <iostream>
#include <iomanip>

// this is a constant pointer to the very employee to which a particular method is applied
Employee::Employee(size_t id, const char* name, const char* position, unsigned int workExperience, double wage)
{
	// validate the values of the input arguments 
	// valid values should be assigned to all data members

	setID(id);
	setName(name);
	setPosition(position);
	setWorkExperience(workExperience);
	setWage(wage);
}

void Employee::setID(size_t newID)
{
	this->id = newID;
}

size_t Employee::getID() const
{
	return this->id;
}

void Employee::setName(const char* newName)
{
	if (newName && strlen(newName) < nameMaxLength)
	{
		strcpy_s(this->name, nameMaxLength, newName);
	}
}

const char* Employee::getName() const
{
	return this->name;
}

void Employee::setPosition(const char* newPosition)
{
	// if the new value is not valid, the position of the current object will not be changed
	if (newPosition && strlen(newPosition) < positionMaxLength)
	{
		strcpy_s(this->position, positionMaxLength, newPosition);
	}
}

const char* Employee::getPosition() const
{
	return this->position;
}

void Employee::setWorkExperience(size_t newWorkExperience)
{
	// if the new value is not valid, the work experience will be not be changed
	if (newWorkExperience >= 0 && newWorkExperience <= 40)
	{
		this->workExperience = newWorkExperience;
	}
}

unsigned int Employee::getWorkExperience() const
{
	return this->workExperience;
}

void Employee::setWage(double newWage)
{
	if (newWage >= 0)
	{
		this->wage = newWage;
	}
}

double Employee::getWage() const
{
	return this->wage;
}

void Employee::showInfo() const
{
	std::cout << std::setw(5) << this->id
		<< std::setw(20) << this->name
		<< std::setw(20) << this->position
		<< std::setw(10) << this->workExperience
		<< std::setw(10) << std::setiosflags(std::ios::fixed) << std::setprecision(2) << this->wage << std::endl;
}

