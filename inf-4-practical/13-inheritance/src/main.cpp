#include <iostream>
#include "Zergling.h"
#include "Raveger.h"
#include "RavegerZergling.h"
#include "Baneling.h"

int main() {
    Zergling zerg;
    Raveger rav;
    Baneling bane;
    Unit* uPtr = &bane;
    uPtr->duel(zerg);

    uPtr->print();
    return 0;
}
