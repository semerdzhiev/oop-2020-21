#include <iostream>
#include <string.h>

#include "computer.h"

int Computer::idGen = 0;

Computer::Computer()
{
    serial = idGen++;
    hardDrive = 0;
    weight = 0;
    battery = 0;
    price = 0;
    quantity = 0;
}

Computer::Computer(const std::string &brand, const std::string &processor, const std::string &video, int hardDrive, double weight, double battery, double price, int quantity)
{
    this->serial = serial;
    this->brand = brand;
    this->processor = processor;
    this->video = video;
    this->hardDrive = hardDrive;
    this->weight = weight;
    this->battery = battery;
    this->price = price;
    this->quantity = quantity;
}

void Computer::print() const
{
    std::cout << "Brand: " << brand << "\nProcessor: " << processor << "\nVideo: " << video << "\nHard: " << hardDrive << "\nPrice: " << price << "\nQuantity: " << quantity << std::endl;
}