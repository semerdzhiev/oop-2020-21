//
// Created by petko on 26/04/2021.
//

#include "Hero.h"

#include <utility>
Hero::Hero(std::string name, std::vector<Power> powers, unsigned short heath, Vilian worstEnemy, std::string motto) :
        Entity(std::move(name),std::move(powers),heath), worstEnemy(std::move(worstEnemy)),
        motto(std::move(motto)) {}

void Hero::addPower(const Power &power) {
    if(power.vilHero==VILIANORHERO::HERO)
        powers.push_back(power);
}