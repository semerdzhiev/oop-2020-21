#include <iostream>
#include "student.h"
#include "university.h"

int main()
{
    int students_num = 2;
    Student *newStudents = new (std::nothrow) Student[students_num];

    for (int i = 0; i < students_num; i++)
    {
        newStudents[i].read();
    }

    University myUniversity;

    myUniversity.createStudents(newStudents, students_num);

    // Additional student
    Student student;
    student.read();

    myUniversity+=student;

    // Printing the additional student
    std::cout<< myUniversity[2];

    myUniversity.sort(fn, asc);

    myUniversity.print();

    myUniversity.clean();

    return 0;
}