#pragma once
#include "item.h"
class Store
{
	Item* items;
	size_t size;
	size_t currentItem;
public:
	Store(); //add 10 items by default
	~Store();
	Store(const Store& other);
	void addItem(const Item& item);

};

