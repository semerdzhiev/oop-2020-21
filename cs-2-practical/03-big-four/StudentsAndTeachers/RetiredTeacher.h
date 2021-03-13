//Създайте още един нов клас RetiredTeacher, който има име и години опит в преподаването.
// Също има поле, което пази всички курсове, който е преподавал през живота си.
// Вашата задача е да опишете класа с полета, които имат нужните типове за лесна работа с
// този клас, функционалността която трябва да поддържа класа е добавяне на нов курс,
// проверка дали е преподавал даден курс(по име и по самия курс), метод, който показва пълна
// информация за учителя и за всички курсове, които е преподавал.
//
#pragma once
#include "DynamicArray.h"
#include "Course.h"
class RetiredTeacher {
private:
    char* name;
    unsigned short experience;
    DynamicArray<Course> courses;

public:
    RetiredTeacher();
    RetiredTeacher(char* _name,unsigned short _exp);
    RetiredTeacher(char* _name,unsigned short _exp, DynamicArray<Course>& _courses);
    RetiredTeacher(const RetiredTeacher& rt);
    RetiredTeacher& operator=(const RetiredTeacher& rt);
    ~RetiredTeacher();

public:
    const char* getName() const;
    unsigned short getExperience() const;
    void setName(const char* _name);
    void setExperience(unsigned short _exp);

public:
    void addCourse(const Course& course);
    bool checkCourse(const Course& course) const;
    void printInformation() const;
};

