#pragma once

#include "Client.h"

const int DEFAULT_CAPACITY = 4;

class Supermarket {

	Client* clients;
	int size;
	int capacity;

	void expand();
	void copy(const Supermarket& other, bool doClean);
	void clean();

public:

	Supermarket();
	Supermarket(const Supermarket& other);
	Supermarket& operator=(const Supermarket& other);
	~Supermarket();

	void add(const Client& client);
};

