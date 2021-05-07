#pragma once
#include "component.h"

class Processor : public Component {
public:
    Processor(const std::string &characteristic) : Component(characteristic){};
};