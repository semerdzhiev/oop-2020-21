#include "chair.h"

Chair::Chair(long id, long length, long width, long height, double price, int qty, ChairType type) : Furniture(length, width, height, price, qty)
{
    this->id = id;
    this->type = type;
}

Chair::Chair(long length, long width, long height, double price, int qty, ChairType type) : Furniture(length, width, height, price, qty)
{
    this->type = type;
}

std::string Chair::getType() const
{
    switch (type)
    {
        case METAL:
            return std::string("Metal");
            
        case WOOD:
            return std::string("Wood");
            
        case PLASTIC:
            return std::string("Plastic");
    }

    return "N/A";
}

void Chair::print(ostream &out) const
{
    out << "Chair " << this->getId() << " " << this->getLength() << " " << this->getWidth() << " " << this->getHeight() << " " << this->getType() << " " << this->getPrice() << " " << this->getQty() << std::endl;
}

Chair* Chair::read(istream &in)
{
    long id;
    long length;
    long width;
    long height;
    double price;
    int qty;
    ChairType chairT;

    in >> id >> length >> width >> height;
    std::string type;
    in >> type;

    if (type == "Metal")
    {
        chairT = METAL;
    }
    else if (type == "Wood")
    {
        chairT = WOOD;
    }
    else if (type == "Plastic")
    {
        chairT = PLASTIC;
    }

    in >> price >> qty;

    Chair* newChair = new Chair(id, length, width, height, price, qty, chairT);
    
    return newChair;
}