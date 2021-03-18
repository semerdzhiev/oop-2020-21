
#ifndef OOP_TEST_WEAPON_H
#define OOP_TEST_WEAPON_H


class Weapon {
private:
    char name[20];
    int power;
    int durability;

public:
    Weapon();
    Weapon(const char newName[20], int newPower, int newDurability);
    int use();
    const char *getName() const;
};


#endif //OOP_TEST_WEAPON_H
