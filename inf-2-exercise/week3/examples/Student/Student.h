#pragma once

#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    string UCN;
    int fn;
    double grades[5];

    bool bornInMarch();
    double avgGrade();
};

