#include <iostream>
#include <cstring>
#include "student.h"

using std::cin;
using std::cout;
using std::endl;

void Student::read()
{
    char tmp[MAX_STRING];

    cout << "Name: ";
    cin >> tmp;
    name = new (std::nothrow) char[strlen(tmp)];
    strcpy(name, tmp);

    cout << "Surname: ";
    cin >> tmp;
    surname = new (std::nothrow) char[strlen(tmp)];
    strcpy(surname, tmp);

    cout << "Family: ";
    cin >> tmp;
    family = new (std::nothrow) char[strlen(tmp)];
    strcpy(family, tmp);

    cout << "EGN: ";
    cin >> egn;

    cout << "Faculty number: ";
    cin >> faculty_number;

    for (int i = 0; i < NUMBER_OF_SUBJECTS; i++)
    {
        marks[i].read();
    }
}

void Student::print()
{
    cout << name << ' ' << surname << ' ' << family << endl;
    cout << "EGN: " << egn << endl;
    cout << "FN: " << faculty_number << endl;
    cout << "Average: " << getAverage() << endl;
}

void Student::printFN()
{
    cout << "FN: " << faculty_number << endl;
    for (int i = 0; i < NUMBER_OF_SUBJECTS; i++)
    {
        cout << marks[i].subject << " - " << marks[i].value << endl;
    }
}

char *Student::getName()
{
    return name;
}

char *Student::getFN()
{
    return faculty_number;
}

double Student::getAverage() const
{
    double sum = 0;

    for (int i = 0; i < NUMBER_OF_SUBJECTS; i++)
    {
        sum += marks[i].value;
    }

    return sum / NUMBER_OF_SUBJECTS;
}

void Student::clean()
{
    delete[] name;
    delete[] surname;
    delete[] family;
    for (int i = 0; i < NUMBER_OF_SUBJECTS; i++)
    {
        marks[i].clean();
    }
}

ostream &operator<<(ostream &out, Student const &student)
{
    out << student.name << ' ' << student.surname << ' ' << student.family << endl;
    out << "EGN: " << student.egn << endl;
    out << "FN: " << student.faculty_number << endl;
    out << "Average: " << student.getAverage() << endl;

    return out;
}