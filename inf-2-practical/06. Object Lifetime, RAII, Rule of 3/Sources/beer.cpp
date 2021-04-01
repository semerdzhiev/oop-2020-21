#include <iostream>
#include <cstring>
#include "../Headers/beer.hpp"

void Beer::copyFrom(const Beer &other)
{
    brand = new char[strlen(other.brand) + 1];
    strcpy(brand, other.brand);
    volume = other.volume;
    abv = other.abv;
}

void Beer:: free()
{
    delete[] brand;
}

Beer:: Beer()
{
    brand = new char[1];
    brand[0] = '\0';
}

Beer:: Beer(const char *_brand, unsigned _volume, double _abv) : volume(_volume), abv(_abv)
{
    brand = new char[strlen(_brand) + 1];
    strcpy(brand, _brand);
}

Beer& Beer:: operator=(const Beer &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Beer:: ~Beer()
{
    free();
}

void Beer:: print()
{
    std::cout << brand << " " << volume << " " << abv << std::endl;
}