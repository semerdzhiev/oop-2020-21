#include <iostream>
#include "structs.h"
#include "helpers.cpp"

using std::cin;
using std::cout;
using std::endl;

void Mark::read() {
    char tmp[MAX_STRING];

    cout << "Subject name: ";
    cin >> tmp;
    subject = new (std::nothrow) char[strlen(tmp)];
    strcpy(subject, tmp);

    cout << "Mark: ";
    cin >> value;
}

void Mark::clean() {
    delete[] subject;
}

void Student::read()
{
    char tmp[MAX_STRING];

    cout << "Name: ";
    cin >> tmp;
    if (tmp[0] >= 'a' && tmp[0] <= 'z')
    {
        tmp[0] += ('A' - 'a');
    }
    name = new (std::nothrow) char[strlen(tmp)];
    strcpy(name, tmp);

    cout << "Surname: ";
    cin >> tmp;
    if (tmp[0] >= 'a' && tmp[0] <= 'z')
    {
        tmp[0] += ('A' - 'a');
    }
    surname = new (std::nothrow) char[strlen(tmp)];
    strcpy(surname, tmp);

    cout << "Family: ";
    cin >> tmp;
    if (tmp[0] >= 'a' && tmp[0] <= 'z')
    {
        tmp[0] += ('A' - 'a');
    }
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

void Student::printFullName()
{
    cout << name << ' ' << family << endl;
}

double Student::getAverage()
{
    double sum = 0;

    for (int i = 0; i < NUMBER_OF_SUBJECTS; i++)
    {
        sum += marks[i].value;
    }

    return sum / NUMBER_OF_SUBJECTS;
}

void Student::clean() {
    delete[] name;
    delete[] surname;
    delete[] family;
    for (int i = 0; i < NUMBER_OF_SUBJECTS; i++)
    {
        marks[i].clean();
    }
}