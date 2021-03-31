#ifndef UNTITLED_COMPANY_H
#define UNTITLED_COMPANY_H

#include "Employee.h"

class Company {
public:
    Company();

    void addEmployee(const Employee& empl);
    bool fireEmployee(const Employee& empl);
    bool isEmpty() const;
    void sort();
    double totalSalary() const;
    bool increase(const char* name, double perc);
    void print() const;
    void printByDept(const char *dept) const;
    double salaryByDept(const char *dept) const;

private:
    Employee employees[1000];
    int size;
};

#endif //UNTITLED_COMPANY_H
