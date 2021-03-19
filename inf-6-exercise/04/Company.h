#ifndef COMPANY_H_INCLUDED
#define COMPANY_H_INCLUDED

#include "Employee.h"

class Company
{
	public:
		Company(const char* theName);

		const char* getName() const;
		void setName(const char* newName);

		size_t getCountEmployees() const;

		// the count of employees is changed only when the array of employees is changed 
		bool hireEmployee(const Employee& newEmployee);
		bool fireEmployee(size_t id);
		
		double findSalaryExpenses() const;

		void showInfo() const;

	private:
		char name[20];

		Employee employees[20];
		size_t countEmployees;
};

#endif // !COMPANY_H_INCLUDED
