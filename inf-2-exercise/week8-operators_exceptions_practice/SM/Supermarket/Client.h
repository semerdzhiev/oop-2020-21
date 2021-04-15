#pragma once

#include "ProductCollection.h"
#include <string>

class Client {
	std::string name;
	ProductCollection pc;

public:

	Client(std::string name = "", ProductCollection pc = ProductCollection());

	std::string getName();
	ProductCollection getProductCollection();
};

