#include "../headers/Company.hpp"
#include <algorithm>
#include <cassert>

unsigned Company::count() const
{
    return m_count;
}

void Company::print_employees() const
{
    std::for_each(m_employees, m_employees + m_count, [](const Employee &employee) {
        employee.print();
    });
}

bool Company::empty() const
{
    return m_count == 0;
}

void Company::add(const Employee &employee)
{
    assert(m_count != 1000);
    m_employees[m_count++] = employee;
}

bool Company::fire(const char *name)
{
    assert(m_count != 0);
    auto employee_ptr = get_employee(name);
    if (employee_ptr == nullptr)
    {
        return false;
    }
    for (auto current_employee_ptr = employee_ptr + 1; current_employee_ptr != m_employees + m_count; ++current_employee_ptr)
    {
        *(current_employee_ptr - 1) = *current_employee_ptr;
    }
    m_count--;
    return true;
}

void Company::sort()
{
    std::sort(m_employees, m_employees + m_count, [](const Employee &employee1, const Employee &employee2) {
        return strcmp(employee1.get_name(), employee2.get_name()) < 0;
    });
}
void Company::raise_salary(const char *name, unsigned percentage)
{
    auto employee_ptr = get_employee(name);
    auto current_salary = employee_ptr->get_salary();
    auto new_salary = current_salary + ((current_salary * percentage) / 100);
    employee_ptr->set_salary(new_salary);
}

Employee* Company::get_employee(const char *name)
{
    for (unsigned i = 0; i < m_count; i++)
    {
        if (std::strcmp(name, m_employees[i].get_name()) == 0)
        {
            return m_employees + i;
        }
    }
    return nullptr;
}