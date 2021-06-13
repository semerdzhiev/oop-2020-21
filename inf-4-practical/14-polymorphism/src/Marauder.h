//
// Created by atanas on 1.06.21 г..
//

#ifndef STARCRAFT_MARAUDER_H
#define STARCRAFT_MARAUDER_H


#include "Unit.h"

class Marauder : public Unit {
public:
    Marauder() : Unit(15, 30, 2, "Marauder") {}

    virtual void attackUnit(Unit &other) override {
        Unit::attackUnit(other);
        setHitPoints(getHitPoints() + 5);
    }

    Unit * clone() const override
    {
        return new Marauder(*this);
    }
};


#endif //STARCRAFT_MARAUDER_H
