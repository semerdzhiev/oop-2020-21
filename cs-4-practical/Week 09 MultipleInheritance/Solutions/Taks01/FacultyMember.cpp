#include "FacultyMember.hpp"

FacultyMember::FacultyMember(const std::string name, const int number, const double salary) : Student(name, number), Employee(name, salary), Person(name)
{
    //No implementation
}