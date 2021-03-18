#pragma once
#include "../headers/Employee.hpp"

class Company
{
public:
    Company() = default;

    unsigned count() const;
    void print_employees() const;
    bool empty() const;
    void add(const Employee &employee);
    bool fire(const char *name);
    void sort();
    void raise_salary(const char *name, unsigned percentage);

private:
    Employee* get_employee(const char *name);
    Employee m_employees[1000]{};
    unsigned m_count{};
};