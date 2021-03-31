#include "../Headers/Company.h"
#include "../Headers/Employee.h"

#include <cstring>
#include <cassert>

Company::Company() {
    size = 0;
}

void Company::addEmployee(const Employee &empl) {
    assert(size < 1000);
    employees[size++] = empl;
}

bool Company::fireEmployee(const Employee &empl) {
    int index = 0;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (employees[i].equal(empl)) {
            index = i;
            found = true;
            break;
        }
    }
    if (found) {
        employees[index] = employees[size - 1];

//        for (int i = index; i < size - 1; ++i) {
//            employees[i] = employees[i + 1];
//        }

        size -= 1;
    }

    return found;
}

bool Company::isEmpty() const {
    return size == 0;
}

void Company::sort() {
 // TODO
}

double Company::totalSalary() const {
    if (isEmpty()) return 0;

    double total = 0;

    for (int i = 0; i < size; ++i) {
        total += employees[i].getSalary();
    }

    return total;
}

bool Company::increase(const char* name, double perc) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(name, employees[i].getName()) == 0) {
            double salary = employees[i].getSalary();
            employees[i].setSalary(salary * (1 + perc));

            return true;
        }
    }

    return false;
}

void Company::print() const {
    for (int i = 0; i < size; ++i) {
        employees[i].print();
    }
}

void Company::printByDept(const char *dept) const {
    for (int i = 0; i < size; i++) {
        if (strcmp(employees[i].getDepartment(), dept) == 0) {
            employees[i].print();
        }
    }
}

double Company::salaryByDept(const char *dept) const {
    double total = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(employees[i].getDepartment(), dept) == 0) {
            total += employees[i].getSalary();
        }
    }

    return total;
}
