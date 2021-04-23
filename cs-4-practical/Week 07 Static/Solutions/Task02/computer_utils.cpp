#include "computer_utils.h"

bool ComputerUtils::isGoodForGaming(Computer *comp) {
    bool isProcessorOK = comp->getProcessor().compare("i5") == 0 || comp->getProcessor().compare("i7") == 0;
    bool isVideoOK = comp->getVideo().compare("3060") == 0 || comp->getVideo().compare("3070") == 0 
                    || comp->getVideo().compare("3080") == 0 || comp->getVideo().compare("3090") == 0; 
    bool isHardOK = comp->getHardDrive() > 512;

    return isProcessorOK && isVideoOK && isHardOK;
}

bool ComputerUtils::isGoodForTravel(Computer *comp) {
    bool isWeightOK = comp->getWeight() < 2.5;
    bool isBatteryOK = comp->getBatteryLife() > 6; 

    return isWeightOK && isBatteryOK;
}
