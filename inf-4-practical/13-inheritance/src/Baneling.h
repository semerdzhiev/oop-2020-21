#pragma once

#include "Unit.h"

class Baneling : public Unit {
public:
    Baneling() : Unit(15, 30, 1, "Baneling") {}

    void attackUnit(Unit &other) {
        Unit::attackUnit(other);
        other.takeDamage(getHitPoints());
        setHitPoints(0);
    }
};