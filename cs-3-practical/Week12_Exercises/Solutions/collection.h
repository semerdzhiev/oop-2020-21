#pragma once
#include "furniture.h"
#include <vector>

class Collection {
    std::vector<Furniture*> items;

public:
    void add(Furniture* item);
    void remove(long id);
    void print(long id);
    void save();
    void load();
};