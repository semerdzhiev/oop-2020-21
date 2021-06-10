#include "PrintCommand.h"

void PrintCommand::execute(std::vector<std::string> arguments, AnimalArray& animals) {
	for (int i = 0; i < animals.size(); ++i) {
		animals[i].print();
	}
}
