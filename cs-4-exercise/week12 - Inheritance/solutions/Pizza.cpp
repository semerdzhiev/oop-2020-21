#include "Pizza.h"
#include <string>
#include <iostream>


Pizza::Pizza(const std::string type,
	const int weight, const int parts,
	const double price) : Food(weight, parts, price) {
	this->type = type;
}

void Pizza::print() {
	std::cout << "Type: " << this->type << std::endl;
	Food::print();
	std::cout << std::endl;
}

void Pizza::category() {
	std::cout << "PIZZA" << std::endl;
}

Food* Pizza::clone() {
	return new Pizza(*this);
}
