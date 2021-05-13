#include <iostream>
#include <string.h>

#include "FacultyMember.hpp"

int main()
{
    FacultyMember facultyMember = FacultyMember("Pesho", 123, 1500);

    std::cout << facultyMember.getName() << std::endl;
    std::cout << facultyMember.getNumber() << std::endl;
    std::cout << facultyMember.getSalary() << std::endl;
}