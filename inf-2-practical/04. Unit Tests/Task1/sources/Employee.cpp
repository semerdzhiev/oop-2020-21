#include "../headers/Employee.hpp"
#include <cassert>
#include <cstring>
#include <iostream>

Employee::Employee(const char *name, unsigned age, unsigned salary) : m_age{age}, m_salary{salary}
{
    assert(name && std::strlen(name) < 50);
    assert(age >= 18 && age <= 64);
    assert(salary >= 610 && salary <= 10000);
    std::strcpy(m_name, name);
}

void Employee::print() const
{
    std::cout << "Name: " << m_name << std::endl
              << "Age: " << m_age << std::endl
              << "Salary: " << m_salary << std::endl;
}

const char *Employee::get_name() const
{
    return m_name;
}

unsigned Employee::get_age() const
{
    return m_age;
}

unsigned Employee::get_salary() const
{
    return m_salary;
}

void Employee::set_name(const char *name)
{
    assert(name && std::strlen(name) < 50);
    std::strcpy(m_name, name);
}

void Employee::set_age(unsigned age)
{
    assert(age >= 18 && age <= 64);
    m_age = age;
}

void Employee::set_salary(unsigned salary)
{
    assert(salary >= 610 && salary <= 10000);
    m_salary = salary;
}
