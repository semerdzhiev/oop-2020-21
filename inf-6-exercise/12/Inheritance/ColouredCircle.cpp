#define _CRT_SECURE_NO_WARNINGS

#include "ColouredCircle.h"

#include <cstring>

// всеки клас се грижи за собствените си член-данни
ColouredCircle::ColouredCircle(const Point& center, double r, const char* colour)
{
    this->setColour(colour);

    std::cout << "\n ColouredCircle created" << std::endl;
    print();
}

ColouredCircle::ColouredCircle(const ColouredCircle& other)
    : Circle(other)
{
    this->setColour(other.colour);
}

ColouredCircle& ColouredCircle::operator=(const ColouredCircle& other)
{
    if (this != &other)
    {
        Circle::operator=(other);
        this->setColour(other.colour);
    }

    return *this;
}

ColouredCircle::~ColouredCircle()
{
    std::cout << "\n ~ColouredCircle:" << std::endl;
    print();

    delete[] this->colour;
    this->colour = nullptr;
}

void ColouredCircle::print() const
{
    Circle::print();
    std::cout << "Colour " << this->colour << std::endl;
}

void ColouredCircle::setColour(const char* colour)
{
    if (!colour) colour = "white";

    char* temp = new char[strlen(colour) + 1];
    strcpy(temp, colour);

    delete[] this->colour;
    this->colour = temp;
}




