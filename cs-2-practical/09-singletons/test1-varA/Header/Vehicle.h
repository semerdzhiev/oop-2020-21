#pragma once

#include "Registration.h"
#include<string>

class Vehicle {
public:
    const Registration regnum;
    const std::string description;

    Vehicle(const char *regnum, const char *description);
};
