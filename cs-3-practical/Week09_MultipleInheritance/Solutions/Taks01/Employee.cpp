#include "Employee.hpp"

Employee::Employee(const std::string name, const double salary) : Person(name)
{
    this->salary = salary;
}

double Employee::getSalary() const
{
    return this->salary;
}