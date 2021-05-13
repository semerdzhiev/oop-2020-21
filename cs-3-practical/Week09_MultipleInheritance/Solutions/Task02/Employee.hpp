#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.hpp"

class Employee : virtual public Person
{
    double salary;

public:
    Employee(const std::string name, const double salary);

    double getSalary() const;
};

#endif