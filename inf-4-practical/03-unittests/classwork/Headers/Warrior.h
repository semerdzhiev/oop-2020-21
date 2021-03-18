
#ifndef OOP_TEST_WARRIOR_H
#define OOP_TEST_WARRIOR_H


#include "Weapon.h"

class Warrior {
private:
    char name[20];
    int strength;
    int health;
    Weapon weapon;

public:
    Warrior(const char *name, int newStrength, int newHealth, Weapon newWeapon);

    const char *getName() const;
    void attack(Warrior& enemy);
    bool isDead() const;
    void equip(const Weapon& newWeapon);

};


#endif //OOP_TEST_WARRIOR_H
