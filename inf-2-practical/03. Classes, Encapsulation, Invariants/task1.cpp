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
