//
// Created by petko on 17/05/2021.
//

#include "Lecturer.h"
#include<iostream>
Lecturer::Lecturer(const char *name, const char *ucn, float salary) : Person(name,ucn), salary(salary){
    std::cout<<"Lecturer()\n";
}

float Lecturer::getSalary() const {
    return salary;
}

void Lecturer::setSalary(float salary) {
    this->salary=salary;
}
void Lecturer::printJobTittle() {
    std::cout<<"Lecturer\n";
}