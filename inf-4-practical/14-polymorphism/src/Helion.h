//
// Created by atanas on 1.06.21 г..
//

#ifndef STARCRAFT_HELION_H
#define STARCRAFT_HELION_H


#include "Unit.h"

class Helion: public Unit {
public:

    virtual void attackUnit(Unit &other) override {
        other.setArmor(getArmor() - 1);
        Unit::attackUnit(other);
    }

    Unit * clone() const override
    {
        return new Helion(*this);
    }
    Helion() : Unit(35, 500, 7, "Helion") {}
};


#endif //STARCRAFT_HELION_H
