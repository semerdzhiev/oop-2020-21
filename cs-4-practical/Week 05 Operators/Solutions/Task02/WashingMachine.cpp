#include <cstring>
#include <fstream>

#include "WashingMachine.hpp"

using std::endl;
using std::istream;
using std::ostream;

WashingMachine::WashingMachine()
{
    strcpy(brand, "\0");
    strcpy(model, "\0");
    acceptableWeight = 0;
    energy = 0.0;
    water = 0;
}

bool WashingMachine::operator>(const WashingMachine &wm)
{
    return acceptableWeight > wm.acceptableWeight ||
           energy < wm.energy ||
           water < wm.water;
}

WashingMachine &WashingMachine::operator=(const WashingMachine &wm)
{
    strcpy(brand, wm.brand);
    strcpy(model, wm.model);
    acceptableWeight = wm.acceptableWeight;
    energy = wm.energy;
    water = wm.water;

    return *this;
}

ostream &operator<<(ostream &out, WashingMachine const &wm)
{
    out << wm.brand << " " << wm.model << endl;

    return out;
}

istream &operator>>(istream &in, WashingMachine &wm)
{
    in.ignore();
    in.getline(wm.brand, MAX_STRING);
    in.getline(wm.model, MAX_STRING);
    in >> wm.acceptableWeight;
    in >> wm.energy;
    in >> wm.water;

    return in;
}