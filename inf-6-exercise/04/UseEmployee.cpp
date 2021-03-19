#include "Company.h"
#include "Employee.h"

#include <iostream>

int main()
{
	Company bright("Bright");
	bright.showInfo();

	Employee me{ 1, "Me", "Teacher", 15, 50 };
	Employee you{ 2, "You", "Programmer", 5, 150 };

	bright.hireEmployee(me);
	bright.hireEmployee(you);

	bright.showInfo();
	std::cout << "Expenses for salaries: " << bright.findSalaryExpenses() << std::endl;

	bright.fireEmployee(me.getID());
	
	std::cout << "-- Someone has been fired?! --" << std::endl;
	bright.showInfo();

	return 0;
}
