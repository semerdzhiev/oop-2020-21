#pragma once
#include "Student.h"
#include "Lecturer.h"

class FacultyMember : public Student, public Lecturer{
public:
    FacultyMember(const char* name, const char* ucn, unsigned int facultyNum, float salary);

    void printJobTittle() override;
};


