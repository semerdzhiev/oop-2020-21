#pragma once

#include <vector>
#include "Unit.h"

class Army
{
public:
    Army(const std::string& name) : name(name) {}
    Army(std::initializer_list<Unit*> list) : units(list) {}
    Army(const Army& other)
    {
        copy(other);
        name = other.name;
    }
    Army& operator=(const Army& other)
    {
        if (this != &other)
        {
            copy(other);
            name = other.name;
        }
        return *this;
    }

    const Unit* operator[](size_t index) const
    {
        return units[index];
    }
    Unit* operator[](size_t index)
    {
        return units[index];
    }

    void addUnit(const Unit* unit)
    {
        units.push_back(unit->clone());
    }

    Army& goToWar(Army& otherArmy)
    {
        size_t our = 0, ourMax = otherArmy.getSize();
        size_t other = 0, otherMax= otherArmy.getSize();
        while (our < ourMax && other < otherMax) {
            units[our]->duel(*otherArmy[other]);
            if (!otherArmy[other]->isAlive()) {
                std::cout << otherArmy.name << "'s " << otherArmy[other]->getName() << " dies!" << std::endl;
                ++other;
            }

            if (!units[our]->isAlive()) {
                std::cout << name << "'s " << units[our]->getName() << " dies!" << std::endl;
                ++our;
            }
        }

        if (our < ourMax -1 && units[our]->isAlive())
        {
            std::cout << name << " Wins!" << std::endl;
            return *this;
        }

        if (other < otherMax -1 && otherArmy[other]->isAlive())
        {
            std::cout << otherArmy.name << " Wins!" << std::endl;
            return otherArmy;
        }

        throw std::runtime_error("No winner");
    }

    size_t getSize() const
    {
        return units.size();
    }
    size_t getCapacity() const
    {
        return units.capacity();
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Army::name = name;
    }

private:

    void copy(const Army& other)
    {
        units.clear();
        units.reserve(other.units.size());
        for (int i = 0; i < other.units.size(); ++i) {
            units.push_back(other.units[i]->clone());
        }
    }

    std::vector<Unit*> units;
    std::string name;
};