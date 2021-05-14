#include <fstream>
#include <iostream>
#include <string.h>

#include "FacultyMember.hpp"

FacultyMember::FacultyMember(const std::string name, const int number, const double salary) : Student(name, number), Employee(name, salary), Person(name)
{
    //No implementation
}

void FacultyMember::save(char * fileName) {
    std::ofstream out(fileName);   

    out << getName() << " ";
    out << getNumber() << " ";
    out << getSalary();
    
    out.close();
}

FacultyMember FacultyMember::read(char * fileName) {
    std::string name;
    int number;
    double salary;

    std::ifstream in(fileName);

    in >> name;
    in >> number;
    in >> salary;
   
    in.close();

    return FacultyMember(name, number, salary);
}

void FacultyMember::print() const
{
    std::cout << "Name: " << getName() << 
    std::endl << "Number: " << getNumber() <<
    std::endl << "Salary: " << getSalary();
}