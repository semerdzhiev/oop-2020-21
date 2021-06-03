#include "furniture.h"
#include <iostream>
#include <exception>

long Furniture::CURR_ID = 0;

Furniture::Furniture()
{
    this->id = 0;
    this->length = 0;
    this->width = 0;
    this->height = 0;
    this->price = 0;
    this->qty = 0;
}

Furniture::Furniture(long length, long width, long height, double price, int qty) 
{
    this->id = Furniture::CURR_ID++;
    this->length = length;
    this->width = width;
    this->height = height;
    this->price = price;
    this->qty = qty;
}

long Furniture::getId() const
{
    return id;
}

long Furniture::getLength() const
{
    return length;
}

long Furniture::getWidth() const
{
    return width;
}

long Furniture::getHeight() const
{
    return height;
}

double Furniture::getPrice() const
{
    return price;
}

int Furniture::getQty() const
{
    return qty;
}

void Furniture::addQty(int newQty)
{
    qty += newQty;
}

void Furniture::removeQty(int newQty)
{
    if (qty - newQty > 0) {
        qty -= newQty;
    } else {
        throw std::invalid_argument("Removed quantity is more than available");
    }
    return ;
}

void Furniture::print(ostream &out) const
{
    out << std::endl;
}