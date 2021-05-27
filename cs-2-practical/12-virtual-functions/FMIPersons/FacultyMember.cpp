//
// Created by petko on 17/05/2021.
//

#include "FacultyMember.h"
#include<iostream>

FacultyMember::FacultyMember(const char *name, const char *ucn, unsigned int facultyNum, float salary) :
        Person(name, ucn),
        Lecturer(name, ucn, salary),
        Student(name, ucn, facultyNum) {}

void FacultyMember::printJobTittle() {
    std::cout<<"Faculty member\n";
}