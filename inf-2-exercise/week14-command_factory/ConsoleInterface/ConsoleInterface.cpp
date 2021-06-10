#include "ConsoleInterface.h"
#include "Fox.h"
#include "Turtle.h"

#include "AddCommand.h"
#include "CommandFactory.h"

#include <iostream>

using namespace std;

void ConsoleInterface::addAnimal(Animal* animal) {
	animals.add(animal);
}

void ConsoleInterface::startReading() {
	string command;
	while (true) {
		getline(cin, command);

		int i = 0, j = 0;
		vector<string> commandArguments;
		while (i < command.size()) {
			for (; j < command.size() && command[j] != ' '; ++j);
			commandArguments.push_back(command.substr(i, j - i));
			for (; j < command.size() && command[j] == ' '; ++j);
			i = j;
		}

		if (commandArguments.size() == 0) {
			std::cout<< "not enough arguments"<< std::endl;
			continue;
		}

		if (commandArguments[0] == "exit") {
			std::cout << "exiting"<< std::endl;
			break;
		}

		ICommand* command = CommandFactory::getCommand(commandArguments);
		if (command == NULL) {
			std::cout << "invalid command";
			continue;
		}
		command->execute(commandArguments, animals);
		delete command;
	}
}
