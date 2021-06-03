#include <iostream>
#include <string.h>

#include "Car.h"

void Car::copy(double maxSpeed, double currentSpeed, double price)
{
    this->maxSpeed = maxSpeed;
    this->currentSpeed = currentSpeed;
    this->price = price;
}

Car::Car()
{
    maxSpeed = 0.0;
    currentSpeed = 0.0;
    price = 0.0;
}

Car::Car(double maxSpeed, double currentSpeed, double price)
{
    this->copy(maxSpeed, currentSpeed, price);
}

Car::Car(Car const &other)
{
    this->copy(other.maxSpeed, other.currentSpeed, other.price);
}

Car &Car::operator=(Car const &other)
{
    if (this != &other)
    {
        this->copy(other.maxSpeed, other.currentSpeed, other.price);
    }

    return *this;
}

Car::~Car()
{
}

void Car::startEngine()
{
    std::cout << "Starting engine" << std::endl;
}

void Car::stopEngine()
{
    std::cout << "Stopping engine" << std::endl;
}