#include <iostream>
#include <string.h>

#include "FamilyCar.h"

FamilyCar::FamilyCar()
{
}

FamilyCar::FamilyCar(double maxSpeed, double currentSpeed, double price) : Car(maxSpeed, currentSpeed, price)
{
}

FamilyCar::FamilyCar(FamilyCar const &other) : Car(other)
{
}

FamilyCar &FamilyCar::operator=(FamilyCar const &other)
{
    if (this != &other)
    {
        this->copy(other.getMaxSpeed(), other.getCurrentSpeed(), other.getPrice());
    }

    return *this;
}

FamilyCar::~FamilyCar()
{
}

void FamilyCar::startMovement() {
    setCurrentSpeed(20);
}

void FamilyCar::stopMovement()
{
    setCurrentSpeed(0);
}

void FamilyCar::accelerate()
{
    setCurrentSpeed(getCurrentSpeed() + 30);
}
