#include "bed.h"

Bed::Bed(long id, long length, long width, long height, double price, int qty) : Furniture(length, width, height, price, qty)
{
    this->id = id;
}

Bed::Bed(long length, long width, long height, double price, int qty) : Furniture(length, width, height, price, qty){};

void Bed::print(ostream &out) const
{
    out << "Bed " << this->getId() << " " << this->getLength() << " " << this->getWidth() << " " << this->getHeight() << " " << this->getPrice() << " " << this->getQty() << std::endl;
}

Bed* Bed::read(istream &in)
{
    long id;
    long length;
    long width;
    long height;
    double price;
    int qty;

    in >> id >> length >> width >> height >> price >> qty;

    Bed *newBed = new Bed(id, length, width, height, price, qty);

    return newBed;
}