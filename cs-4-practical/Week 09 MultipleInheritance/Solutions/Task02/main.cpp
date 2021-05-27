#include <iostream>
#include <string.h>

#include "FacultyMember.hpp"

int main()
{
    std::string name;
    int number;
    double salary;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter number: ";
    std::cin >> number;

    std::cout << "Enter salary: ";
    std::cin >> salary;

    FacultyMember facultyMember = FacultyMember(name, number, salary);

    facultyMember.save("test.txt");

    FacultyMember read = FacultyMember::read("test.txt");

    read.print();
}