#ifndef FACULTY_MEMBER_H
#define FACULTY_MEMBER_H

#include "Student.hpp"
#include "Employee.hpp"

class FacultyMember : public Student, public Employee
{

public:
    FacultyMember(const std::string name, const int number, const double salary);
};

#endif