#include "CommandFactory.h"
#include "AddCommand.h"
#include "PrintCommand.h"

ICommand* CommandFactory::getCommand(vector<string>& arguments) {
	if (arguments.size() < 1) {
		return NULL;
	}

	if (arguments[0] == "add") {
		return new AddCommand();
	} else if (arguments[0] == "print") {
		return new PrintCommand();
	}
}