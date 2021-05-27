#include "Food.h"
#include <cassert>
#include <iostream>

Food::Food(const int weight, const int parts, const double price) {
	assert(weight > 0);
	assert(parts > 0);
	assert(price > 0);
	this->weight = weight;
	this->parts = parts;
	this->price = price;
	this->weightPerPart = (double)weight / parts;
}

void Food::consume() {
	std::cout << "CONSUME" << std::endl;
	assert(parts > 0);
	this->weight -= this->weightPerPart;
	this->parts--;
}


void Food::print() {
	std::cout << "Weigh: " << weight << std::endl;
	std::cout << "Part: " << parts << std::endl;
	std::cout << "WeightPerPart: " << weightPerPart << std::endl;
	std::cout << "Price: " << price << std::endl;
}

int Food::getWeight() const {

	return this->weight;
}

int Food::getParts() const {

	return this->parts;
}

double Food::getPrice() const {

	return this->price;
}

double Food::getWeightPerPart() const {

	return this->weightPerPart;
}

bool Food::operator==(const Food& f) const {
	return this->weight == f.weight &&
		this->price == f.price &&
		this->parts == f.parts &&
		this->weightPerPart == f.weightPerPart;
}

void Food::category() {
	std::cout << "Food" << std::endl;
}