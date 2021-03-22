//Създайте нов клас Course, който има name - име на курса,
// capacity - максимален брой студенти в курса, students -
// записаните студенти в курса. Направете конструктор, сетъри и гетъри
// по ваш избор, аргументирайте решението си. Защо конструктора приема точно тези параметри, з
// ащо точно тези полета имат сетъри и гетъри? Добавете следните публични
// методи за работа с Course
//
//enrolStudent - Метод, който добавя студент към students.
//enrolStudents - Метод, който добавя много студенти наведнъж към students.
//printInformation - Метод, който показва пълната информация за курса - име , капацитет, студенти.

#pragma once

#include <iostream>
#include "Student.h"
#include "DynamicArray.h"
class Course {
private:
    size_t capacity;
    char *name;
    DynamicArray<Student> students;

public:
    Course(char *_name, DynamicArray<Student>& _students, size_t  _capacity=16);
    Course(char *_name,size_t _capacity=16);
    Course();
    Course(const Course& course);
    Course& operator=(const Course& course);
    ~Course();
    bool operator==(const Course& other) const;

public:
    void setCapacity(size_t  _capacity);
    void setName(const char* _name);

    size_t getCapacity() const;
    const char* getName() const;

public:
    void printInformation() const;
    bool enrolStudent(Student& _student);
    void enrolStudents(const DynamicArray<Student>& _students);

public:
    friend std::ostream& operator<<(std::ostream& os, const Course& s);
};
