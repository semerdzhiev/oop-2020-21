//
// Created by petko on 26/04/2021.
//

#include "Entity.h"

#include <utility>
Entity::Entity(std::string name, std::vector<Power> powers, unsigned short heath) : name(std::move(name)),
powers(std::move(powers)), health(heath){}

Power Entity::getPower(size_t index) const {
    return powers[index];
}

bool Entity::drainHealth(unsigned short _health) {
    health-=_health;
    return isDead();
}

bool Entity::isDead() const {
    return this->health <= 0;
}

size_t Entity::getPowersNumber() const {
    return powers.size();
}

unsigned short Entity::getHealth() const {
    return this->health;
}