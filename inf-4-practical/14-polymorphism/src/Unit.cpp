//
// Created by atanas on 25.05.21 г..
//

#include "Unit.h"

int Unit::getAttackPower() const {
    return attack;
}

int Unit::getHitPoints() const {
    return hitPoints;
}

int Unit::getArmor() const {
    return armor;
}

const std::string &Unit::getName() const {
    return name;
}

void Unit::setAttackPower(int attack) {
    if (attack < 0){
        attack = 0;
    }
    this->attack = attack;
}

void Unit::setHitPoints(int hp) {
    if (hp < 0)
    {
        hp = 0;
    }
    hitPoints = hp;
}

void Unit::setArmor(int armor) {
    this->armor = armor;
}

void Unit::setName(const std::string &name) {
    this->name = name;
}

Unit::Unit(int attack, int hitPoints, int armor, const std::string &name) :
        attack(attack), hitPoints(hitPoints), armor(armor), name(name) {}

Unit &Unit::duel(Unit &other) {
    if (this == &other)
    {
        std::cout << "Cannot duel self!" << std::endl;
        return *this;
    }
    std::cout << "Duel started!" << std::endl;
    print();
    other.print();
    while (isAlive())
    {
        attackUnit(other);
        std::cout << name << " attacked " << other.name << " - " << other.hitPoints << std::endl;
        if (!other.isAlive())
        {
            std::cout << name << " wins!" << std::endl;
            return *this;
        }
        other.attackUnit(*this);
        std::cout << other.name << " attacked " << name << " - " << hitPoints << std::endl;
    }
    std::cout << other.name << " wins!" << std::endl;
    return other;
}

void Unit::attackUnit(Unit &other) {
    other.takeDamage(attack);
}

void Unit::takeDamage(int damage) {
    int mitigated = armor > damage ? 0 : damage - armor;
    hitPoints -= mitigated;
}

bool Unit::isAlive() const {
    return hitPoints > 0;
}

void Unit::print(std::ostream &out) const {
    out << name << ": HP:" << hitPoints << " attack: " << attack << " armor: " << armor << std::endl;
}

Unit *Unit::clone() const {
    return new Unit(*this);
}
