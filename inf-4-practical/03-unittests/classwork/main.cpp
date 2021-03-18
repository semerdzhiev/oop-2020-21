#include <iostream>
#include "Headers/Warrior.h"
#include "Headers/Weapon.h"

int main() {
    Weapon w1("sword", 5, 5);
    Weapon w2("mechka", 7, 3);
    Warrior warrior1("Pesho", 5, 100, w1);
    Warrior warrior2("Gosho", 7, 100, w2);

    while (!warrior1.isDead() && !warrior2.isDead()) {
        warrior1.attack(warrior2);
        if (warrior2.isDead()) {
            break;
        }

        warrior2.attack(warrior1);
    }

    if (warrior1.isDead()) {
        std::cout << warrior2.getName() << " won!" << std::endl;
    } else {
        std::cout << warrior1.getName() << " won!" << std::endl;
    }

    return 0;
}

