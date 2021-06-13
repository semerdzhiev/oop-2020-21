#include <iostream>
#include "Zergling.h"
#include "Raveger.h"
#include "RavegerZergling.h"
#include "Baneling.h"
#include "Army.h"
#include "Marine.h"
#include "Helion.h"
#include "Marauder.h"

int main() {
    Zergling* zerg = new Zergling();
    Raveger* rav = new Raveger();
    Baneling* bane = new Baneling;
    Unit* uPtr = bane;

    Army army1 = {zerg, rav, bane};
    army1.setName("Army1");

    Marine* mar = new Marine();
    Helion* hel = new Helion();
    Marauder* marauder = new Marauder();

    Army army2 = {mar, hel, marauder};
    army2.setName("Army2");

//    army1.goToWar(army2);

    std::cout << typeid(*bane).name() << std::endl;
    std::cout <<typeid(*uPtr).name();

    return 0;
}
