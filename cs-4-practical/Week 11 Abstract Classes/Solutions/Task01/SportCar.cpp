#include <iostream>
#include <string.h>

#include "SportCar.h"

SportCar::SportCar()
{
}

SportCar::SportCar(double maxSpeed, double currentSpeed, double price) : Car(maxSpeed, currentSpeed, price)
{
}

SportCar::SportCar(SportCar const &other) : Car(other)
{
}

SportCar &SportCar::operator=(SportCar const &other)
{
    if (this != &other)
    {
        this->copy(other.getMaxSpeed(), other.getCurrentSpeed(), other.getPrice());
    }

    return *this;
}

SportCar::~SportCar()
{
}

void SportCar::startMovement() {
    setCurrentSpeed(50);
}

void SportCar::stopMovement()
{
    setCurrentSpeed(0);
}

void SportCar::accelerate()
{
    setCurrentSpeed(getCurrentSpeed() + 100);
}
