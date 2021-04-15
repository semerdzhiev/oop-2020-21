#include <iostream>
#include <cstring>
#include "university.h"

void University::createStudents(Student *newStudents, int newSize)
{
    size = newSize;
    students = new Student[size];
    for (int i = 0; i < size; i++)
    {
        students[i] = newStudents[i];
    }
}

void University::sort(Field field, Order order)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (compare(students[i], students[j], field, order))
            {
                Student tmp = students[i];
                students[i] = students[j];
                students[j] = tmp;
            }
        }
    }
}

bool University::compare(Student studA, Student studB, Field field, Order order)
{
    switch (field)
    {
    case name:
        return order == asc ? strcmp(studA.getName(), studB.getName()) > 0 : strcmp(studA.getName(), studB.getName()) < 0;
    case fn:
        return order == asc ? strcmp(studA.getFN(), studB.getFN()) > 0 : strcmp(studA.getFN(), studB.getFN()) < 0;
    case averageScore:
        return order == asc ? studA.getAverage() > studB.getAverage() : studA.getAverage() > studB.getAverage();
    default:
        return false;
    }
}

University &University::operator+=(Student const &student)
{
    Student* newStudents = new Student[++size];
    
    for (int i = 0; i < size - 1; i++)
    {
        newStudents[i] = students[i];
    }

    newStudents[size - 1] = student;

    students = newStudents;

    return *this;
}

Student &University::operator[](int const position)
{
    return students[position];
}

void University::print() const
{
    for (int i = 0; i < size; i++)
    {
        students[i].print();
    }
}

void University::clean()
{
    for (int i = 0; i < size; i++)
    {
        students[i].clean();
    }

    size = 0;
    delete[] students;
}