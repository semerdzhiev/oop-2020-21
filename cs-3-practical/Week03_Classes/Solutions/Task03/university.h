#ifndef UNIVERSITY
#define UNIVERSITY

#include "student.h"
#include "enums.h"

class University {
    Student* students;
    int size = 0;

    bool compare(Student studA, Student studB, Field field, Order order);

public:
    void createStudents(Student *students, int size);
    void sort(Field field, Order order);
    void print();
    void clean();
};

#endif