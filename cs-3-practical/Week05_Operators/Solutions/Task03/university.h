#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "student.h"
#include "enums.h"

class University
{
    Student *students;
    int size = 0;

    bool compare(Student studA, Student studB, Field field, Order order);

public:
    void createStudents(Student *students, int size);
    void sort(Field field, Order order);

    University &operator+=(Student const &student);
    Student &operator[](int const position);

    void print() const;
    void clean();
};

#endif