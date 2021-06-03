#pragma once
#include "furniture.h"
#include <iostream>

using std::ostream;

class Bed : public Furniture {
    Bed(long id, long length, long width, long height, double price, int qty);

public:
    Bed(long length, long width, long height, double price, int qty);
    void print(ostream &out) const;
    static Bed* read(istream &in);
};