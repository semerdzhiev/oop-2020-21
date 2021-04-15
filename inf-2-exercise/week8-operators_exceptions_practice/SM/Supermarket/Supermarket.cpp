#include "Supermarket.h"

void Supermarket::expand() {
	Client* temp = new Client[capacity * 2];
	for (int i = 0; i < size; ++i) {
		temp[i] = clients[i];
	}

	delete[] clients;
	clients = temp;
	capacity *= 2;
}

void Supermarket::copy(const Supermarket& other, bool doClean = true) {
	if (doClean) {
		clean();
	}

	capacity = other.capacity;
	size = other.size;
	clients = new Client[capacity];

	for (int i = 0; i < size; ++i) {
		clients[i] = other.clients[i];
	}
}

void Supermarket::clean() {
	delete[] clients;
	clients = nullptr;
	size = 0;
	capacity = 0;
}

Supermarket::Supermarket(): clients(new Client[DEFAULT_CAPACITY]), size(0), capacity(DEFAULT_CAPACITY) {}

Supermarket::Supermarket(const Supermarket& other) {
	copy(other, false);
}

Supermarket& Supermarket::operator=(const Supermarket& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

Supermarket::~Supermarket() {
	clean();
}

void Supermarket::add(const Client& client) {
	if (size == capacity) {
		expand();
	}

	clients[size++] = client;
}
