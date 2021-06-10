#pragma once

#include <vector>
#include <string>

#include "AnimalArray.h"

class ICommand {
public:
	virtual void execute(std::vector<std::string> arguments, AnimalArray& animals) = 0;
};