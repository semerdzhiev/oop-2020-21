#pragma once

class Employee
{
public:
    // constructors
    Employee() = default;
    Employee(const char *, unsigned, unsigned);

    //print method
    void print() const;

    // accessors
    const char *get_name() const;
    unsigned get_age() const;
    unsigned get_salary() const;

    // mutators
    void set_name(const char *name);
    void set_age(unsigned age);
    void set_salary(unsigned salary);
    
private:
    char m_name[51]{};
    unsigned m_age{20};
    unsigned m_salary{1000};
};