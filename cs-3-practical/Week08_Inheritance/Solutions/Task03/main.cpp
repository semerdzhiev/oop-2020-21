#include <iostream>
#include "student.h"

int main()
{
    Student student1;
    student1.print();
    std::cout << std::endl;

    Student student2("John", "Doe", 32, 2312, "Informatics");
    student2.print();

    return 0;
}