#include "Store.h"
#include "Item.h"
Store::Store()
{
	this->size = 10;
	this->items = new Item[10]; //Error handling...
	this->currentItem = 0;
}

Store::~Store()
{
	delete[] this->items;
	size = 0;
}

Store::Store(const Store& other)
{
	// TBW
}

void Store::addItem(const Item& item)
{
	this->items[this->currentItem] = item;
	this->currentItem++;
}
