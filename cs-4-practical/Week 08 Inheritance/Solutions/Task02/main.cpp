#include <iostream>
#include "computer.h"

int main() {

    Processor processor("Intel i7 3.4 GHz");
    Ram ram("32 GB");
    HardDrive hard("SAMSUNG 512 gb");
    VideoCard video("ATI Radeon 2 GB");

    Computer myComp(hard, video, processor, ram);
    myComp.print();

    return 0;
}