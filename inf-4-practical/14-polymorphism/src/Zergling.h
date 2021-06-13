#include "Unit.h"

#pragma once

class Zergling : public Unit {
public:
    Zergling() :  Unit(10, 30, 1, "Zergling") {}

    Unit * clone() const override
    {
        return new Zergling(*this);
    }
};