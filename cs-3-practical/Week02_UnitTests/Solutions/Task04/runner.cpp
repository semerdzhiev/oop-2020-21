#include <iostream>
#include "runner.h"
#include "helpers.cpp"

using std::cin;
using std::cout;
using std::endl;

void Runner::read()
{
    char tmp[MAX_STRING];

    cout << "Name:" << endl;
    cin.ignore();
    cin.getline(tmp, MAX_STRING);
    if (tmp[0] >= 'a' && tmp[0] <= 'z')
    {
        tmp[0] += ('A' - 'a');
    }
    name = new (std::nothrow) char[strlen(tmp)];
    strcpy(name, tmp);

    cout << "Family:" << endl;
    cin.getline(tmp, MAX_STRING);
    if (tmp[0] >= 'a' && tmp[0] <= 'z')
    {
        tmp[0] += ('A' - 'a');
    }
    family = new (std::nothrow) char[strlen(tmp)];
    strcpy(family, tmp);

    for (int i = 0; i < NUMBER_OF_MARATHONS; i++)
    {
        cout << i + 1 << " marathon time:" << endl;
        cin >> times[i];
    }
}

double Runner::getPace()
{
    double sum = 0.0;

    for (int j = 0; j < NUMBER_OF_MARATHONS; j++)
    {
        sum += times[j];
    }

    return sum / NUMBER_OF_MARATHONS;
}

int Runner::beatNtimes(Runner *other)
{
    int number = 0;

    for (int j = 0; j < NUMBER_OF_MARATHONS; j++)
    {
        if (times[j] < other->times[j])
        {
            number++;
        }
    }

    return number;
}

void Runner::clean() {
    delete[] name;
    delete[] family;
}