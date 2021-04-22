#ifndef COMPUTER_UTILS
#define COMPUTER_UTILS

#include "computer.h"
#include <cstring>

class ComputerUtils {
public:
    static bool isGoodForGaming(Computer *comp);
    static bool isGoodForTravel(Computer *comp);
};

#endif