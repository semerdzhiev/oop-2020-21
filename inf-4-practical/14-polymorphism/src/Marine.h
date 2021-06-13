//
// Created by atanas on 1.06.21 г..
//

#ifndef STARCRAFT_MARINE_H
#define STARCRAFT_MARINE_H


#include "Unit.h"

class Marine : public  Unit {
public:
    Marine() : Unit(10, 25, 2, "Marine") {}

    Unit * clone() const override
    {
        return new Marine(*this);
    }
};


#endif //STARCRAFT_MARINE_H
