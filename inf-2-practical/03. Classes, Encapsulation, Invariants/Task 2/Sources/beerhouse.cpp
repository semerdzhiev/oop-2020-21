#include "../Headers/beerhouse.hpp"
#include <cassert>
#include <cstring>

//Beerhouse:: Beerhouse()

unsigned Beerhouse:: getNumberOfBeers () const {
    return number;
}


void Beerhouse:: addBeer(const Beer& newBeer) 
{
    assert(number <  MAX_BEERS_NUMBER); 
    beers[number++] = newBeer;
}

void shift(Beer* current, Beer* last)
{
    for(Beer* ptr = current+1; ptr!=last; ptr++)
    {
        *(ptr-1) = *ptr;
    }
}

const Beer& Beerhouse:: sellBeer(const char* _brand, double _volume)
{
    Beer* resultPtr;
    Beer result;

//търсенето на елемента може да се изнесе в отделен метод, но в случая не го правим, 
//защото ни трябва и количеството и това прави случая по-специфичен и може би няма да 
//се наложи още някъде да търсим бири по този начин

    for(Beer* beer = beers; beer != beers + number; beer++) 
    {
        if(strcmp(beer->getBrand(), _brand)==0)
        { 
            resultPtr = beer;
            
            if(beer->getVolume() ==_volume)
                break;
        }
    }

    result = *resultPtr;
    shift(resultPtr, beers+number);
    number--;
    return result;
}

void Beerhouse:: print() const
{
    for(int i=0; i<number; ++i) 
    {
        beers[i].print();
    }
}

bool Beerhouse:: isEmpty() const
{
    return number==0;
}
