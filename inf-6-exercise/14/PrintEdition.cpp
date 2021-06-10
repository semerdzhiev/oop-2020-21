#include "PrintEdition.h"

#include <iostream>
#include <stdexcept>

PrintEdition::PrintEdition(const std::string& title, unsigned int yearOfPublishing, double price)
	: title(title), yearOfPublishing(yearOfPublishing)
{
	if (price < 0)
		throw std::invalid_argument("Invalid price value!");

	this->price = price;
}

void PrintEdition::print() const
{
	std::cout << "Title: " << this->title << std::endl;
	std::cout << "Price: " << this->price << std::endl;
	std::cout << "Year Of Publishing: " << this->yearOfPublishing << std::endl;

	this->printOwnData();
}
