#pragma once

#include "AnimalArray.h"

class ConsoleInterface {
	AnimalArray animals;

	void addAnimal(Animal* animal);
public:
	void startReading();
};

