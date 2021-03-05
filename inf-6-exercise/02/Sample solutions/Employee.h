#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

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

void readEmployee(Employee& employee);
void printEmployee(const Employee& employee);

#endif // !EMPLOYEE_H_INCLUDED
