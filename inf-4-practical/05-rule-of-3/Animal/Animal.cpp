#include "Animal.h"
#include <cassert>
#include <cstring>
#include <new>
#include <iostream>

Animal::Animal()
{
    name = nullptr;
    type = nullptr;
    age = 0;
    lifespan = 0;
}

Animal::Animal(const char *name, const char *type, unsigned int age, double lifespan)
{
    setName(name);
    setType(type);
    setAge(age);
    setLifespan(lifespan);
}

Animal::Animal(const Animal &rhs)
{
    copy(rhs);
}

Animal &Animal::operator=(const Animal &rhs)
{
    if(this != &rhs)
    {
        delete [] name;
        delete [] type;

        copy(rhs);
    }

    return *this;
}

Animal::~Animal()
{
    delete [] name;
    delete [] type;
}

const char *Animal::getName() const
{
    return name;
}

void Animal::setName(const char* newName)
{
    int len = strlen(newName);
    assert(len > 0);

    this->name = new char[len + 1];
    strncpy(this->name, newName, len + 1);
}

const char *Animal::getType() const
{
    return this->type;
}


void Animal::setType(const char* newType)
{
    int len = strlen(newType);
    assert(len > 0);

    this->type = new char[len + 1];

    strncpy(this->type, newType, len + 1);
}

unsigned int Animal::getAge() const
{
    return age;
}

void Animal::setAge(unsigned int age)
{
    this->age = age;
}

double Animal::getLifespan() const
{
    return lifespan;
}

void Animal::setLifespan(double lifespan)
{
    this->lifespan = lifespan;
}

void Animal::copy(const Animal& rhs)
{
    setName(rhs.name);
    setType(rhs.type);
    setAge(rhs.age);
    setLifespan(rhs.lifespan);
}
