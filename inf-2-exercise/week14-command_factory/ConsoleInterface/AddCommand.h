#pragma once

#include "ICommand.h"

class AddCommand : public ICommand {
public:
	virtual void execute(std::vector<std::string> arguments, AnimalArray& animals);
};

