#include "beer.hpp"

class Beerhouse {

private:
    Beer* beers;
    unsigned capacity{};
    unsigned count{};
    
    void copyFrom(const Beerhouse& other);
    void free();

public: 
    Beerhouse();
    Beerhouse(unsigned _capacity);
    Beerhouse(const Beerhouse& other);
    Beerhouse& operator=(const Beerhouse& other);
    ~Beerhouse();

    void addBeer(const Beer& newBeer);
    void printBeers();
};