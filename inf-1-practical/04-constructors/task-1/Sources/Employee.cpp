#include "../Headers/Employee.h"
#include <cstring>
#include <cassert>
#include <iostream>

Employee::Employee() {
    age = 0;
    salary = 0;
}

Employee::Employee(const char *newName, const char *department, int newAge, double newSalary) {
    setName(newName);
    setDepartment(department);
    setAge(newAge);
    setSalary(newSalary);
}

void Employee::setName(const char *newName) {
    assert(newName && strlen(newName) < 50);

    strcpy(name, newName);
}

void Employee::setDepartment(const char *newDept) {
    assert(newDept && strlen(newDept) < 50);

    strcpy(department, newDept);
}

void Employee::setAge(int newAge) {
    assert(newAge >= 18 && newAge <= 64);
    age = newAge;
}

void Employee::setSalary(double newSalary) {
    assert(newSalary >= 610 && newSalary <= 1000);
    salary = newSalary;
}

const char *Employee::getName() const {
    return name;
}

const char *Employee::getDepartment() const {
    return department;
}

int Employee::getAge() const {
    return age;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::print() const {
    std::cout << name << " " << department << " " << age << " " << salary << std::endl;
}

bool Employee::equal(const Employee &empl) {
    return strcmp(name, empl.name) == 0 &&
        strcmp(department, empl.department) == 0 &&
        age == empl.age && salary == empl.salary;
}
