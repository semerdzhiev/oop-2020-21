#include "Client.h"

Client::Client(std::string name, ProductCollection pc) : name(name), pc(pc) {}

std::string Client::getName() {
	return name;
}

ProductCollection Client::getProductCollection() {
	return pc;
}

double Client::checkout() const {
	double sum = 0;
	for (int i = 0; i < pc.getSize(); ++i) {
		sum += pc[i].getCurrPrice();
	}

	return sum;
}