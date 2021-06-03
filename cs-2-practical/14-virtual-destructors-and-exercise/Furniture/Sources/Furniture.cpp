#include "../Headers/Furniture.h"

Furniture::Furniture(unsigned int ID, unsigned int width,
                     unsigned int height,
                     unsigned int length, int quantity,
                     float price) : ID(ID),
                                    width(width), height(height), length(length),
                                    quantity(quantity), price(price) {}

float Furniture::getPrice() const {
    return price;
}

int Furniture::getQuantity() const {
    return quantity;
}

void Furniture::setPrice(float price) {
    if(price>0)
        this->price = price;
}

void Furniture::setQuantity(int quantity) {
    if(quantity>0)
        this->quantity = quantity;
}


bool Furniture::operator==(const Furniture &other) const {
    return this->ID == other.ID;
}

bool Furniture::operator!=(const Furniture &other) const {
    return !(*this==other);
}
