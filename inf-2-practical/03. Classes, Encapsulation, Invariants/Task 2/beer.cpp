#include "beer.hpp"
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;


void Beer:: setBrand(char _brand[]) 
{
    assert(_brand && strlen(_brand) < MAX_BRAND_LENGTH);
    strcpy(brand, _brand);
}

void Beer:: setAbv(double _abv)
{
    assert(_abv >= MIN_ABV && _abv <= MAX_ABV);
    abv = _abv;
}

void Beer:: setVolume(unsigned _volume) 
{
    assert(_volume >= MIN_VOLUME && _volume <= MAX_VOLUME);
    volume = _volume;
}

Beer:: Beer()
{
    this->brand[0] = '\0';
    //strcpy(this->brand,"\0");
    this->abv = 0;
    this->volume = 0;
}

Beer:: Beer(char _brand[], double _abv, unsigned _volume)
{
    setBrand(_brand); //извикваме сетърите, за да избегнем повторение на код
    setAbv(_abv);
    setVolume(_volume);
}

const char* Beer:: getBrand() const
{
    return brand;
}

double Beer:: getAbv() const
{
    return abv;
}

unsigned Beer:: getVolume() const
{
    return volume;
}

void Beer:: print() const 
{
    cout << brand << " " << abv << "% " << volume << "ml" << endl;
}

