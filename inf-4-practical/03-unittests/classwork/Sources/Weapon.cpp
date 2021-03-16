#include <cstring>
#include "../Headers/Weapon.h"

Weapon::Weapon() {
    strcpy(name, "");
    power = 1;
    durability = 5;
}

Weapon::Weapon(const char newName[20], int newPower, int newDurability) {
    strcpy(name, newName);
    strcat(name, "\0");

    power = newPower;
    durability = newDurability;
}

int Weapon::use() {
    if (durability <= 0) {
        return 0;
    }

    durability--;
    return power;
}

const char *Weapon::getName() const {
    return name;
}