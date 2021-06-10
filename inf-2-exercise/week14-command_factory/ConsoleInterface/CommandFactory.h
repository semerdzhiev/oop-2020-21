#pragma once

#include "ICommand.h"

class CommandFactory {
public:
	static ICommand* getCommand(vector<string>& commandArguments);
};

