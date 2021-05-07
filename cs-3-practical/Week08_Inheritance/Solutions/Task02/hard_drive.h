#pragma once
#include "component.h"

class HardDrive : public Component {
public:
    HardDrive(const std::string &characteristic) : Component(characteristic) {};
};