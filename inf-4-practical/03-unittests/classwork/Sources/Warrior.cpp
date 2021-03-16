
#include <cstring>
#include "../Headers/Warrior.h"

Warrior::Warrior(const char *newName, int newStrength, int newHealth, Weapon newWeapon) {
    strcpy(name, newName);
    strength = newStrength;
    health = newHealth;
    weapon = newWeapon;
}

const char* Warrior::getName() const {
    return name;
}

void Warrior::attack(Warrior &enemy) {
    int weaponAttack = weapon.use();
    int totalAttack = weaponAttack + strength;

    enemy.health -= totalAttack;
}

bool Warrior::isDead() const {
    return health <= 0;
}

void Warrior::equip(const Weapon &newWeapon) {
    weapon = newWeapon;
}
