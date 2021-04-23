#ifndef COMPUTER_SHOP_H
#define COMPUTER_SHOP_H

#include <iostream>
#include "Computer.h"

typedef bool (*Filter)(Computer* computer);

class ComputerShop
{
    Computer *computers;
    int size;
    std::string name;

    void copy(const std::string &name, int size, Computer *computers);

public:
    ComputerShop();
    ComputerShop(const std::string &name, int size, Computer *computers);
    ComputerShop(const ComputerShop &otherComputerShop);
    ComputerShop &operator=(ComputerShop const &otherComputerShop);

    void addComputer(const Computer &computer);
    void buyComputer(const char *brand, double money);
    void print();
    const Computer *getComputersInStock(Filter filter = nullptr);

    const std::string getName() const { return this->name; }
    int getSize() const { return this->size; }
    const Computer *getComputers() const { return this->computers; }

    ~ComputerShop();
};

#endif /* ifndef COMPUTER_SHOP_H */