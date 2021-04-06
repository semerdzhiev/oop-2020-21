#ifndef UNTITLED1_ZOO_H
#define UNTITLED1_ZOO_H

#include "../Animal/Animal.h"

class Zoo {
public:
    Zoo(const char * address, const char *president, double price);
    Zoo(const char * address, const char *president, double price, unsigned capacity);
    ~Zoo();

    void setAddress(const char *address);
    void setPresident(const char *president);
    void setPrice(double price);

    const char *getAddress() const;
    const char *getPresident() const;
    double getPrice() const;
    unsigned getSize() const;

    void addAnimal(const Animal& animal);
    void removeAnimal(const Animal& animal);
    void moveAnimal(const Animal& animal, Zoo &zoo);

private:
    Animal *animals;
    unsigned size;
    unsigned capacity;
    char *address;
    char *president;
    double price;

    Zoo(const Zoo&);
    Zoo& operator=(const Zoo&);

    void resize();
    Animal* getAnimal(const Animal& animal);
};


#endif //UNTITLED1_ZOO_H
