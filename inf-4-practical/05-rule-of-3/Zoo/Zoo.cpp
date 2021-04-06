#include "Zoo.h"
#include <cassert>
#include <cstring>
#include <new>

Zoo::Zoo(const char *address, const char *president, double price) : Zoo(address, president, price, 2)
{
//    setAddress(address);
//    setPresident(president);
//    setPrice(price);
//
//    capacity = 2;
//    size = 0;
//    animals = new Animal[capacity];
}

Zoo::Zoo(const char *address, const char *president, double price, unsigned int capacity)
: address(nullptr), president(nullptr)
{
    setAddress(address);
    setPresident(president);
    setPrice(price);

    this->capacity = capacity;
    size = 0;
    animals = new Animal[capacity];
}

Zoo::~Zoo()
{
    delete [] address;
    delete [] president;
    delete [] animals;
}

void Zoo::setAddress(const char *address)
{
    assert(address);

    if (this->address != nullptr)
    {
        delete [] this->address;
    }

    this->address = new (std::nothrow) char[strlen(address) + 1];
    strcpy(this->address, address);
}

void Zoo::setPresident(const char *president) {
    assert(president);

    if (this->president != nullptr)
    {
        delete [] this->president;
    }

    this->president = new (std::nothrow) char[strlen(president) + 1];
    strcpy(this->president, president);
}

void Zoo::setPrice(double price) {
    assert(price >= 0);

    this->price = price;
}

const char *Zoo::getAddress() const {
    return address;
}

const char *Zoo::getPresident() const {
    return president;
}

double Zoo::getPrice() const {
    return price;
}

unsigned Zoo::getSize() const {
    return size;
}

void Zoo::addAnimal(const Animal& animal) {
    if (capacity == size) {
        resize();
    }

    animals[size] = animal;

    size++;
}

void Zoo::resize() {
    capacity *= 2;

    Animal *temp = new (std::nothrow) Animal[capacity];

    for (int i = 0; i < size; ++i) {
        temp[i] = animals[i];
    }

    delete [] animals;
    animals = temp;
}

void Zoo::removeAnimal(const Animal &animal) {
    unsigned index = -1;
    for (int i = 0; i < size; ++i) {
        if (animals[i].equal(animal)) {
            index = i;
        }
    }

    if (index != -1) {
        animals[index] = animals[size - 1];
        size--;
    }
}

void Zoo::moveAnimal(const Animal &animal, Zoo &zoo) {
    Animal* temp = getAnimal(animal);

    if (temp) {
        removeAnimal(animal);
        zoo.addAnimal(*temp);
    }
}

Animal* Zoo::getAnimal(const Animal& animal) {
    for (int i = 0; i < size; ++i) {
        if (animals[i].equal(animal)) {
            return &animals[i];
        }
    }
    return nullptr;
}









