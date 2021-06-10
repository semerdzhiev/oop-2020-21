#include "Bookstore.h"

#include <iostream>

void Bookstore::print() const
{
	std::cout << "\nBookstore: ( " << this->editions.size() << " ) editions\n";
	for (PrintEdition* currentEdition : this->editions)
	{
		currentEdition->print();
	}
}

void Bookstore::copy(const std::vector<PrintEdition*>& editions)
{
	this->editions.reserve(editions.size());
	for (PrintEdition* currentEdition : editions)
	{
		this->editions.push_back(currentEdition->clone());
	}
}

void Bookstore::clear()
{
	for (PrintEdition* currentEdition : this->editions)
	{
		delete currentEdition;
	}
}

Bookstore::Bookstore(const std::vector<PrintEdition*>& editions)
{
	copy(editions);
}

Bookstore::Bookstore(const Bookstore& other)
	: Bookstore(other.editions)
{}

Bookstore& Bookstore::operator=(const Bookstore& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other.editions);
	}

	return *this;
}

Bookstore::~Bookstore()
{
	this->clear();
}
