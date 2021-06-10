#pragma once

#include "ICommand.h"

#include <iostream>

class PrintCommand : public ICommand {
public:
	virtual void execute(std::vector<std::string> arguments, AnimalArray& animals);
};

