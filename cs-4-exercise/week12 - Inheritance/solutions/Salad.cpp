#include "Salad.h"
#include <iostream>

Salad::Salad(const int productsCount, const bool isSpiced,
	const int weight, const double price) : Food(weight, 1, price) {
	this->productsCount = productsCount;
	this->isSpiced = isSpiced;
}

void Salad::print() {
	std::cout << "Products Count: " << productsCount << std::endl;
	std::cout << "Is Spiced: " << isSpiced << std::endl;
	Food::print();
}

void Salad::category() {
	std::cout << "SALAD" << std::endl;
}

Food* Salad::clone() {
	return new Salad(*this);
}