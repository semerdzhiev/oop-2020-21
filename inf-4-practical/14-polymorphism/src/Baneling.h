#pragma once

#include "Unit.h"

class Baneling : public Unit {
public:
    Baneling() : Unit(15, 30, 1, "Baneling") {}

    virtual void attackUnit(Unit &other) override {
        Unit::attackUnit(other);
        other.takeDamage(getHitPoints());
        setHitPoints(0);
    }

    Unit * clone() const override
    {
        return new Baneling(*this);
    }
};