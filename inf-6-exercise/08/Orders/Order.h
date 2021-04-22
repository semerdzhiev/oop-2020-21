#pragma once

#include "Item.h"

class Order
{
	public:
		Order(const char* clientName);
		Order(const Order& other);
		Order& operator=(const Order& other);
		~Order();

		const char* getClientName() const { return this->clientName; }
		size_t getItemsCount() const { return this->itemsCount; }

		void setClientName(const char* newClient);

		double totalPrice() const;

		Order& operator+=(const Item& item);
		// Order& operator-=(const Item& item);

		Item* operator[](const char* id);
		const Item* operator[](const char* id) const;

		// void print() const;

	private:
		char* clientName{};

		Item* items{};
		size_t itemsCount{};
		size_t capacity{};

	private:
		void copyItems(const Order& other);
		int findItemByCode(const char* code) const;
};