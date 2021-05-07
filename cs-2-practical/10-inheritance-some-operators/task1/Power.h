//
// Created by petko on 26/04/2021.
//

#pragma once.

enum class TYPE {
    FIRE=0,
    LIGHT,
    AIR,
    SOUND
};

enum class VILIANORHERO {
    VILIAN = 0,
    HERO
};

struct Power {
    TYPE typeOfMagic=TYPE::FIRE;
    VILIANORHERO vilHero=VILIANORHERO::HERO;
    unsigned short damage=1;

    Power(const TYPE& type, const VILIANORHERO& vilHero, unsigned short damage);
};


