#include "Client.h"

Client::Client(std::string name, ProductCollection pc) : name(name), pc(pc) {}

std::string Client::getName() {
	return name;
}

ProductCollection Client::getProductCollection() {
	return pc;
}
