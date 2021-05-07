#pragma once
#include "component.h"

class VideoCard : public Component {
public:
    VideoCard(const std::string &characteristic) : Component(characteristic){};
};