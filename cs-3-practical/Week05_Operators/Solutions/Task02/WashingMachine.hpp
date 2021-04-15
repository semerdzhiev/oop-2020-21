#pragma once

#include <fstream>

#define MAX_STRING 32

using std::istream;
using std::ostream;

class WashingMachine
{
private:
    char brand[MAX_STRING];
    char model[MAX_STRING];
    int acceptableWeight;
    double energy;
    int water;

public:
    WashingMachine();

    WashingMachine &operator=(const WashingMachine &wm);
    bool operator>(const WashingMachine &wm);

    friend istream &operator>>(istream &in, WashingMachine &wm);
    friend ostream &operator<<(ostream &out, const WashingMachine &wm);
};