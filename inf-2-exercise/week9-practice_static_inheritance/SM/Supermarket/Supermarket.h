#pragma once

#include <vector>

#include "Client.h"
#include "MultiQueue.h"

const int DEFAULT_CAPACITY = 4;

class Supermarket {

	std::vector<Client> clients;
	ProductCollection products;
	MultiQueue queues;

public:

	void add(const Client& client);
};