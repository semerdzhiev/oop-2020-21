#include <iostream>
#include <cstring>
#include "mark.h"

using std::cout;
using std::cin;

void Mark::read()
{
    char tmp[MAX_STRING];

    cout << "Subject name: ";
    cin >> tmp;
    subject = new (std::nothrow) char[strlen(tmp)];
    strcpy(subject, tmp);

    cout << "Mark: ";
    cin >> value;
}

void Mark::copy(Mark newMark) {
    strcpy(subject, newMark.subject);
    value = newMark.value;
}

void Mark::clean()
{
    delete[] subject;
}