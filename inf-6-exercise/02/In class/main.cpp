#include <iostream>

// Допълнителни задачи:
// 1. Каква част от кода бихте изнесли в header файл?
// 2. Довършете реализациите на функциите read & print.

// 3. Дефинирайте структура от данни, която описва Компания със следните характеристики:
// а) име на компанията;
// б) CEO (служител)
// в) брой служителите и самите служители.

// Дефинирайте функции, които позволяват:
// а) добавяне на служител;
// б) освобождаване (съкращаване) на служител;
// в) намиране на общия месечен разход на компанията за заплати на служителите, 
// ако се предполага, че средно в един месец има 22 работни дни.

const size_t nameMaxLength = 20;
const size_t positionMaxLength = 20;

struct Employee
{
	size_t id{ 0 };
	char name[nameMaxLength]{};
	char position[positionMaxLength]{};
	unsigned int workExperience{ 0 };
	double wage{ 0.0 };
};

void readEmployee(Employee& employee)
{

}

// оформете изхода по следния начин:
// ИД (посравнено вляво, 5 позиции) Име (20 позиции) Позиция (20 позиции) Стаж (подравнено вдясно) Надница (подравнено вдясно, 2 символа след .)
void printEmployee(const Employee& employee)
{
	std::cout << "ID: " << employee.id
		<< "\tName: " << employee.name
		<< "\tPosition: " << employee.position
		<< "\tWork experience: " << employee.workExperience
		<< "\tWage: " << employee.wage << std::endl;
}

void simpleTests()
{
	Employee e;

	std::cout << "Size of Employee: " << sizeof(Employee) << std::endl;

	// cannot read an employee directly
	//std::cin >> e;

	e.id = 1;
	strcpy_s(e.name, nameMaxLength, "Me");
	strcpy_s(e.position, positionMaxLength, "Teacher");
	e.workExperience = 15;
	e.wage = 40.50;

	printEmployee(e);

	// how to define a pointer to a structure variable?
	Employee* ptrEmployee = &e;

	// how to access data members using the pointer?
	ptrEmployee->wage += 20;
	// equavalent to 
	(*ptrEmployee).wage -= 20;

	// what will happen if the structure variable is copied?
	Employee cloning = e;
	std::cout << "-- The cloning --" << std::endl;
	printEmployee(cloning);

	// what if we try to change the copy? 
	// what will happen to the original?
	cloning.workExperience += 1;

	std::cout << "-- The changed cloning --" << std::endl;
	printEmployee(cloning);

	std::cout << "-- The original --" << std::endl;
	printEmployee(e);
}

// find the most experienced employee
int findMostExperiencedEmployee(const Employee* employees, size_t count)
{
	if (!employees || !count)
		return -1;

	size_t indexMostExperienced = 0;

	for (size_t currentIndex = 1; currentIndex < count; ++currentIndex)
	{
		if (employees[indexMostExperienced].workExperience < employees[currentIndex].workExperience)
		{
			indexMostExperienced = currentIndex;
		}
	}

	return indexMostExperienced;
}

// sort the employees by workexperience in descending order
void sort(Employee* employees, size_t count)
{
	if (!employees || !count)
		return;

	for (size_t index = 0; index < count - 1; ++index)
	{
		// search in the rest of the array without the first element
		size_t indexMostExperienced = findMostExperiencedEmployee(employees + index, count - index);

		// in order to get the index of this element in the bigger (original) array
		indexMostExperienced += index;

		std::swap(employees[indexMostExperienced], employees[index]);
	}
}

// what if we use an additional array of pointers?
// ascending order, bubble sort, array of pointers
void sort(Employee** pEmployees, size_t count)
{
	if (!pEmployees || !count)
		return;

	for (size_t i = 0; i < count - 1; ++i)
	{
		for (size_t j = i + 1; j < count; ++j)
		{
			if (pEmployees[i]->workExperience > pEmployees[j]->workExperience)
			{
				std::swap(pEmployees[i], pEmployees[j]);
			}
		}
	}
}

int main()
{
	// simpleTests();

	Employee employees[10];
	Employee* pEmployees[10]{ nullptr };

	std::cout << "Number of employees? ";
	size_t numberOfEmployees = 0;
	std::cin >> numberOfEmployees;

	for (size_t i = 0; i < numberOfEmployees; ++i)
	{
		readEmployee(employees[i]);
		pEmployees[i] = &employees[i];
	}

	size_t indexMostExperienced = findMostExperiencedEmployee(employees, numberOfEmployees);
	std::cout << "The most experienced employee is: " << std::endl;
	printEmployee(employees[indexMostExperienced]);

	std::cout << "\n-- Sorted employees --\n";
	sort(pEmployees, numberOfEmployees);

	for (size_t i = 0; i < numberOfEmployees; ++i)
	{
		printEmployee(*pEmployees[i]);
	}

	return 0;
}
