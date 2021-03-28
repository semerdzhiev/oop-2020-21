#include "Item.h"
#include <string>
Item::~Item()
{
}

double Item::getPrice() const {
	return this->price * this->getApplicableDiscount();
}

Item::Item(const Item& item) {
	this->id = item.id;
	this->price = item.price;
	this->applicableDiscound = item.applicableDiscound;
	this->typeProduct = item.typeProduct;
}

int Item::getID() const {
	return this->id;
}

void Item::setPrice(double price) {
	this->price = price;
}

void Item::setTypeProduct(int typeProduct) {
	this->typeProduct = typeProduct;
}


const double Item::getApplicableDiscount() const {
	return this->applicableDiscound;
}

Item::Item()
{	
	this->applicableDiscound = 1;
}

Item::Item(int id, double price) {
	this->id = id;
	this->price = price;
	this->applicableDiscound = 1;
}

const int Item::getQuantity() const {
	return this->quantity;
}

void Item::setQuantity(int quantity) {
	this->quantity = quantity;
}