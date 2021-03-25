#include <iostream>
#include "student.h"
#include "teacher.h"
#include "university.h"

int main()
{
    // int students_num = 2;
    // Student *newStudents = new (std::nothrow) Student[students_num];

    // for (int i = 0; i < students_num; i++)
    // {
    //     newStudents[i].read();
    // }

    // University<Student> myUniversity;
    // myUniversity.createPeople(newStudents, students_num);
    // myUniversity.sort(name, asc);
    // myUniversity.print();
    // myUniversity.clean();


    int teachers_num = 2;
    Teacher *newTeachers = new (std::nothrow) Teacher[teachers_num];

    for (int i = 0; i < teachers_num; i++)
    {
        newTeachers[i].read();
    }

    University<Teacher> myUniversity2;
    myUniversity2.createPeople(newTeachers, teachers_num);
    myUniversity2.sort(name, asc);
    myUniversity2.print();
    myUniversity2.clean();

    return 0;
}