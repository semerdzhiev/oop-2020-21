#include <string>
#include <iostream>

#pragma once

class Unit
{
public:
    Unit() = default;
    Unit(int attack, int hitPoints, int armor, const std::string& name);
    virtual ~Unit() = default;

    Unit& duel(Unit& other);

    virtual void attackUnit(Unit& other);

    virtual Unit* clone() const;

    void takeDamage(int damage);
    bool isAlive() const;

    void print(std::ostream& out = std::cout) const;

    int getAttackPower() const;
    int getHitPoints() const;
    int getArmor() const;
    const std::string& getName() const;

    void setAttackPower(int attack);
    void setHitPoints(int hp);
    void setArmor(int armor);
    void setName(const std::string& name);

//    private | public = private
private:
    int attack;
    int hitPoints;
    int armor;
    std::string name;
};