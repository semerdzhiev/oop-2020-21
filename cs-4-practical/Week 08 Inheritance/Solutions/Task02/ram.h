#pragma once
#include "component.h"

class Ram : public Component {
public:
    Ram(const std::string &characteristic) : Component(characteristic){};
};