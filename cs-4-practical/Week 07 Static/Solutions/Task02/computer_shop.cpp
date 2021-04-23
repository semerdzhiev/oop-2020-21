#include <iostream>

#include "computer_shop.h"

void ComputerShop::copy(const std::string &name, int size, Computer *computers)
{
    this->name = name;
    this->size = size;

    this->computers = new Computer[size];
    for (int i = 0; i < size; i++) {
        this->computers[i] = Computer(computers[i]);
    }
}

ComputerShop::ComputerShop()
{
    size = 0;
    computers = nullptr;
}

ComputerShop::ComputerShop(const std::string &name, int size, Computer *computers)
{
    this->copy(name, size, computers);
}

ComputerShop::ComputerShop(ComputerShop const &otherComputershop)
{
    this->copy(otherComputershop.name, otherComputershop.size, otherComputershop.computers);
}

ComputerShop &ComputerShop::operator=(ComputerShop const &otherComputerShop)
{
    if (this != &otherComputerShop)
    {
        delete[] this->computers;
        this->copy(otherComputerShop.name, otherComputerShop.size, otherComputerShop.computers);
    }

    return *this;
}

ComputerShop::~ComputerShop()
{
    if (computers != nullptr)
    {
        delete[] computers;
    }
}

void ComputerShop::addComputer(const Computer &computer)
{
    for (int i = 0; i < size; i++)
    {
        if (computers[i].getBrand().compare(computer.getBrand()) == 0)
        {
            computers[i].setQuantity(1);
            return;
        }
    }

    Computer *newComputers = new Computer[size + 1];
    for (int i = 0; i < size; i++)
    {
        newComputers[i] = computers[i];
    }
    newComputers[size++] = computer;

    computers = newComputers;
}

void ComputerShop::buyComputer(const char *brand, double money)
{
    for (int i = 0; i < size; i++)
    {
        if (computers[i].getBrand().compare(brand) == 0)
        {
            if (computers[i].getQuantity() > 0 && money >= computers[i].getPrice())
            {
                computers[i].setQuantity(-1);
                std::cout << "Success" << std::endl;
            }
            else
            {
                std::cout << "Insufficient quantity or money" << std::endl;
            }

            return;
        }
    }

    std::cout << "Brand not found" << std::endl;
}

void ComputerShop::print()
{
    std::cout << name << std::endl;

    for (int i = 0; i < size; i++)
    {
        computers[i].print();
    }
}

const Computer *ComputerShop::getComputersInStock(Filter filter)
{
    int inStockSize = 0;

    for (int i = 0; i < size; i++)
    {
        if ((filter != nullptr || filter(&computers[i])) && computers[i].getQuantity() > 0)
        {
            inStockSize++;
        }
    }

    Computer *computersInStock = new Computer[inStockSize];
    for (int i = 0, j = 0; i < size; i++)
    {
        if ((filter != nullptr || filter(&computers[i])) && computers[i].getQuantity() > 0)
        {
            computersInStock[j++] = computers[i];
        }
    }

    return computersInStock;
}