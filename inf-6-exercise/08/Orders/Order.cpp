#include "Order.h"

#include <cassert>
#include <cstring>
#include <exception>

void Order::copyItems(const Order& other)
{
	this->capacity = other.capacity;
	this->itemsCount = other.itemsCount;

	this->items = new Item[this->capacity];
	for (size_t i = 0; i < this->itemsCount; i++)
	{
		this->items[i] = other.items[i];
	}
}

int Order::findItemByCode(const char* code) const
{
	for (size_t i = 0; i < this->itemsCount; i++)
	{
		if (strcmp(code, items[i].getID()) == 0)
		{
			return i;
		}
	}

	return -1;
}

Order::Order(const char* name)
{
	this->setClientName(name);
}

Order::Order(Order const& other)
{
	this->setClientName(other.clientName);
	this->copyItems(other);
}

Order& Order:: operator=(const Order& other) 
{
	if (this != &other) 
	{
		this->setClientName(other.clientName);

		delete[] this->items;
		this->copyItems(other);
	}

	return *this;
}

Order::~Order()
{
	delete[] this->clientName;
	delete[] this->items;
}

void Order::setClientName(const char* newName)
{
	if (newName == nullptr)
		throw std::exception("Invalid name!");

	size_t nameLen = strlen(newName);
	if (nameLen == 0)
		throw std::exception("Empty name!");

	delete[] this->clientName;

	this->clientName = new char[nameLen + 1];
	strcpy_s(this->clientName, nameLen + 1, newName);
}

Item* Order::operator[](const char* code)
{
	int index = findItemByCode(code);

	if(index == -1)
		return nullptr;

	return &this->items[index];
}

const Item* Order::operator[](const char* code) const
{
	int index = findItemByCode(code);

	if (index == -1)
		return nullptr;

	return &this->items[index];
}

double Order::totalPrice()const 
{
	double price = 0;
	
	for (size_t i = 0; i < this->itemsCount; i++)
	{
		price += this->items[i].getPrice();
	}
	
	return price;
}

Order& Order::operator+=(const Item& other)
{
	if (this->totalPrice() + other.getPrice() > 100)
		return *this;

	if (this->itemsCount < this->capacity)
	{
		this->items[++this->itemsCount] = other;
	}
	else
	{
		Item* temp = new Item[this->capacity + 4];
		for (size_t i = 0; i < this->itemsCount; i++)
			temp[i] = this->items[i];
	
		delete[] this->items;
		
		this->items = temp;
		
		this->capacity += 4;
		this->items[++this->itemsCount] = other;
	}

	return *this;
}