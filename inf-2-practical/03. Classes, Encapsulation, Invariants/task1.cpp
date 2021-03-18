#include <iostream>
#include <cassert>
#include <cstring>
#include <algorithm>

class Employee
{
public:
    // constructors
    Employee() = default;
    
    Employee(const char *name, unsigned age, unsigned salary) : m_age{age}, m_salary{salary}
    {
        assert(name && std::strlen(name) < 50);
        assert(age >= 18 && age <= 64);
        assert(salary >= 610 && salary <= 10000);
        std::strcpy(m_name, name);
    }

    //print method
    void print() const
    {
        std::cout << "Name: " << m_name << std::endl
                  << "Age: " << m_age << std::endl
                  << "Salary: " << m_salary << std::endl;
    }

    // accessors
    const char *get_name() const
    {
        return m_name;
    }
    unsigned get_age() const
    {
        return m_age;
    }
    unsigned get_salary() const
    {
        return m_salary;
    }

    // mutators
    void set_name(const char *name)
    {
        assert(name && std::strlen(name) < 50);
        std::strcpy(m_name, name);
    }
    void set_age(unsigned age)
    {
        assert(age >= 18 && age <= 64);
        m_age = age;
    }
    void set_salary(unsigned salary)
    {
        assert(salary >= 610 && salary <= 10000);
        m_salary = salary;
    }

private:
    char m_name[51]{""};
    unsigned m_age{20};
    unsigned m_salary{1000};
};

class Company
{
public:
    Company() = default;

    unsigned count() const
    {
        return m_count;
    }
    void print_employees() const
    {
        std::for_each(m_employees, m_employees + m_count, [](const Employee &employee) {
            employee.print();
        });
    }
    bool empty() const
    {
        return m_count == 0;
    }
    void add(const Employee &employee)
    {
        assert(m_count != 1000);
        m_employees[m_count++] = employee;
    }
    bool fire(const char *name)
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
    void sort()
    {
        std::sort(m_employees, m_employees + m_count, [](const Employee &employee1, const Employee &employee2) {
            return strcmp(employee1.get_name(), employee2.get_name()) < 0;
        });
    }
    void raise_salary(const char *name, unsigned percentage)
    {
        auto employee_ptr = get_employee(name);
        auto current_salary = employee_ptr->get_salary();
        auto new_salary = current_salary + ((current_salary * percentage) / 100);
        employee_ptr->set_salary(new_salary);
    }

private:
    Employee* get_employee(const char *name)
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
    Employee m_employees[1000]{};
    unsigned m_count{};
};

int main()
{
    Company c{};
    c.add({"Pesho", 25, 650});
    c.add({"Ani", 21, 1000});
    c.add({"Mimi", 30, 3000});
    c.print_employees();
    c.fire("Pesho");
    c.print_employees();
    c.sort();
    c.print_employees();
    c.raise_salary("Ani", 20);
    c.print_employees();
    return 0;
}