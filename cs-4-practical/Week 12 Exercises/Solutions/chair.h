#pragma once
#include "furniture.h"
#include <iostream>
#include <string>

using std::ostream;

enum ChairType {
    METAL, WOOD, PLASTIC
};

class Chair : public Furniture {
    ChairType type;
    Chair(long id, long length, long width, long height, double price, int Qty, ChairType type);

public:
    Chair(long length, long width, long height, double price, int Qty, ChairType type);
    std::string getType() const;
    void print(ostream &out) const;
    static Chair* read(istream &in);
};