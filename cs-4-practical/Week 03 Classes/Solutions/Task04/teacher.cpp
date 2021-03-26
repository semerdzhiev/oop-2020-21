#include <iostream>
#include <cstring>
#include "constants.h"
#include "teacher.h"

using std::cin;
using std::cout;
using std::endl;

void Teacher::read()
{
    char tmp[MAX_STRING];

    cout << "Name: ";
    cin >> tmp;
    name = new (std::nothrow) char[strlen(tmp)];
    strcpy(name, tmp);

    cout << "Family: ";
    cin >> tmp;
    family = new (std::nothrow) char[strlen(tmp)];
    strcpy(family, tmp);

    cout << "Specialty: ";
    cin >> tmp;
    specialty = new (std::nothrow) char[strlen(tmp)];
    strcpy(specialty, tmp);
}

char* Teacher::getName()
{
    return name;
}

char* Teacher::getFN()
{
    return new char[0];
}

double Teacher::getAverage()
{
    return 0;
}

void Teacher::print()
{
    cout << name << ' ' << family << endl;
    cout << "Specialty: " << specialty << endl;
}

void Teacher::clean()
{
    delete[] name;
    delete[] family;
    delete[] specialty;
}