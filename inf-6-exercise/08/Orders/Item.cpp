#define _CRT_SECURE_NO_WARNINGS

#include "Item.h"

#include <cassert>
#include <cstring>

#include <exception>
#include <stdexcept>

bool isValid(const char* newCode)
{
	if (newCode == nullptr)
		return false;

	if (strlen(newCode) != 5)
		return false;

	for (int i = 0; i < 5; i++)
		if (newCode[i] < '0' || newCode[i] > '9')
			return false;

	return true;
}

Item::Item(const char* newCode, const char* newName, double newPrice)
{
	//if (!isValid(newCode))
	//	throw std::exception("Invalid code!");

	//strcpy(this->id, newCode);
	
	//if (newPrice < 0)
	//	throw std::exception("Invalid price!");

	//this->price = newPrice;

	//if (newName == nullptr)
	//	throw std::exception("Invalid name!");

	//this->name = new char[strlen(newName) + 1];
	//strcpy_s(this->name, strlen(newName) + 1, newName);

	try
	{
		this->setID(newCode);
		this->setName(newName);
		this->setPrice(newPrice);
	}
	catch (const std::exception& ex)
	{
		delete[] this->name;

		throw;
	}
}

Item::Item(const Item& other)
	: Item(other.id, other.name, other.price)
{}

Item& Item::operator=(const Item& other)
{
	if (this != &other)
	{
		this->setID(other.id);
		this->setName(other.name);
		this->setPrice(other.price);
	}

	return *this;
}

Item::~Item(){
	delete[] name;
}

void Item::setID(const char* newCode)
{
	if (!isValid(newCode))
		throw std::exception("Invalid code!");

	strcpy(this->id, newCode);
}

void Item::setName(const char* newName)
{ 
	if (newName == nullptr)
		throw std::exception("Invalid name!");

	size_t nameLen = strlen(newName);
	if(nameLen == 0)
		throw std::exception("Empty name!");

	delete[] this->name;

	this->name = new char[nameLen + 1];
	strcpy_s(this->name, nameLen + 1, newName);
}

void Item::setPrice(double newPrice)
{
	if (newPrice < 0)
		throw std::exception("Invalid price!");

	this->price = newPrice;
}

bool operator==(const Item& left, const Item& right)
{
	return strcmp(left.getID(), right.getID()) == 0;
}
