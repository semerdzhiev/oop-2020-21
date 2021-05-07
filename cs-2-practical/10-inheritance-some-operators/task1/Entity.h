//
// Created by petko on 26/04/2021.
//

#pragma once
#include<string>
#include "Power.h"
#include<vector>


class Entity {
public:
    const std::string name;
protected:
    std::vector<Power> powers;
    unsigned short health;
public:
    Entity(std::string  name, std::vector<Power>  powers, unsigned short heath);
    Entity(const Entity& ) = delete;
    Entity& operator=(const Entity&) = delete;
    virtual void addPower(const Power& power)=0;
    Power getPower(size_t index) const;
    size_t getPowersNumber() const;
    unsigned short getHealth() const;
    bool drainHealth(unsigned short health);
    bool isDead() const;
};


