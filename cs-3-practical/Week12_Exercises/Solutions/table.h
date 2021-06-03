#pragma once
#include "furniture.h"
#include <iostream>
#include <string>

using std::ostream;
using std::istream;

enum TableType {
    KITCHEN, COFFEE
};

class Table : public Furniture {
    TableType type;
    Table(long id, long length, long width, long height, double price, int Qty, TableType type);

public:
    Table(long length, long width, long height, double price, int Qty, TableType type);
    std::string getType() const;
    void print(ostream &out) const;
    static Table* read(istream &in);
};