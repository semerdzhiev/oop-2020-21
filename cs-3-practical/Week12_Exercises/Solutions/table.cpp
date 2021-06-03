#include "table.h"

Table::Table(long id, long length, long width, long height, double price, int qty, TableType type) : Furniture(length, width, height, price, qty)
{
    this->id = id;
    this->type = type;
}

Table::Table(long length, long width, long height, double price, int qty, TableType type) : Furniture(length, width, height, price, qty)
{
    this->type = type;
}

std::string Table::getType() const 
{
    switch (type)
    {
        case KITCHEN:
            return "Kitchen";

        case COFFEE:
            return "Coffee";
    }

    return "N/A";
}

void Table::print(ostream &out) const
{
    out << "Table " << this->getId() << " " << this->getLength() << " " << this->getWidth() << " " << this->getHeight() << " " << this->getType() << " " << this->getPrice() << " " << this->getQty() << std::endl;
}

Table* Table::read(istream &in) {
    long id;
    long length;
    long width;
    long height;
    double price;
    int qty;
    TableType tableT;
    
    in >> id >> length >> width >> height;
    std::string type;
    in >> type;

    if (type == "Kitchen") {
        tableT = KITCHEN;
    } else if (type == "Coffee") {
        tableT = COFFEE;
    }

    in >> price >> qty;

    Table* newTable = new Table(id, length, width, height, price, qty, tableT);

    return newTable;
}