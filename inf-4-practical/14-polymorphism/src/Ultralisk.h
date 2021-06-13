#pragma once

#include "Unit.h"

class Ultralisk : public Unit {
public:
    Ultralisk() : Unit(35, 500, 5, "Ultralisk") {}

    void attackUnit(Unit &other) override {
        Unit::attackUnit(other);
        other.takeDamage(getArmor());
    }

    Unit * clone() const override
    {
        return new Ultralisk(*this);
    }
};
