#include <iostream>

#include "AddCommand.h"
#include "Fox.h"
#include "Turtle.h"

void AddCommand::execute(std::vector<std::string> arguments, AnimalArray& animals) {

	if (arguments.size() < 2) {
		std::cout << "not enough arguments for animal creation" << std::endl;
		return;
	}

	if (arguments[1] == "fox") {
		if (arguments.size() < 4) {
			std::cout<<  "not enough arguments for fox creation"<< std::endl;
			return;
		}

		string name = arguments[2];
		int age = stoi(arguments[3]);

		animals.add(new Fox(name, age, Fox::Type::Canis));
	} else if (arguments[1] == "turtle") {
		if (arguments.size() < 5) {
			std::cout<< "not enough arguments for turtle creation"<< std::endl;
			return;
		}

		string name = arguments[2];
		int age = stoi(arguments[3]);
		int shellDiameter = stoi(arguments[4]);

		animals.add(new Turtle(name, age, shellDiameter));
	} else {
		std::cout << "we don't have many animals and that's definetly one of the ones we have" << std::endl;
	}
}
