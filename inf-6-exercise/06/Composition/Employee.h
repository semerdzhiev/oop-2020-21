#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Date.h"

class Employee
{
public:
	Employee() = default;
	Employee(const char* name, const char* position, double salary, const Date& specifiedDate);

	void setName(const char* newName);
	void setPosition(const char* newPosition);
	void setSalary(double newSalary);
	void setHiredOn(const Date& date);

	double getSalary() const;
	const char* getName() const;
	const char* getPosition() const;
	Date getHiredOn() const;

	void print() const;

private:
	char name[20]{};
	char position[20]{};
	double salary{ 610 };
	Date hiredOn;
};

#endif // !EMPLOYEE_H_INCLUDED
