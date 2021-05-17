#include "Student.h"
#include<iostream>

Student::Student(const char *name, const char *ucn, const unsigned int facultyNum) : Person(name,ucn), facultyNum(facultyNum) {
    std::cout<<"Student()\n";
}

unsigned int Student::getFacultyNum() const {
    return facultyNum;
}

void Student::printJobTittle() {
   std::cout<<"Student\n";
}