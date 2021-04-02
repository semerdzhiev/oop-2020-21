#include "../Headers/beerhouse.hpp"


void Beerhouse:: copyFrom(const Beerhouse &other)
{
    beers = new Beer[other.capacity];

    for (unsigned i = 0; i < other.count; i++)
    {
        beers[i] = other.beers[i];
    }
    capacity = other.capacity;
    count = other.count;
}

void Beerhouse:: free()
{
    delete[] beers;
}

Beerhouse:: Beerhouse()
{
    beers = new Beer[capacity];
}

Beerhouse:: Beerhouse(unsigned _capacity)
{
    capacity = _capacity;
    beers = new Beer[_capacity];
    count = 0;
}

Beerhouse:: Beerhouse(const Beerhouse &other)
{
    copyFrom(other);
}

Beerhouse& Beerhouse:: operator=(const Beerhouse &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Beerhouse:: ~Beerhouse()
{
    free();
}

void Beerhouse:: addBeer(const Beer &newBeer)
{
    beers[count++] = newBeer;
}

void Beerhouse:: printBeers()
{
    for (int i = 0; i < count; i++)
    {
        beers[i].print();
    }
}
