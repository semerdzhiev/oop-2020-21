#pragma once

#include "Unit.h"

class Raveger : public Unit {
public:
    Raveger() : Unit(20, 100, 3, "Raveger"), attacksCount(2) {}

    virtual void attackUnit(Unit &other) override {
        ++attacksCount;
        if (attacksCount % 3 == 0) {
            attacksCount = 0;
            setAttackPower(getAttackPower() * 2);
            Unit::attackUnit(other);
            setAttackPower(getAttackPower() / 2);
        }
    }

    Unit * clone() const override
    {
        return new Raveger(*this);
    }
private:
    int attacksCount;
};

