#pragma once

#include "beer.hpp"

const unsigned MAX_BEERS_NUMBER = 1000;

class Beerhouse 
{
private:
    Beer beers[MAX_BEERS_NUMBER]{};
    unsigned number{};

public:
  
  //тук трябва да се замислим дали са ни необходими конструктури, гетъри и сетъри,
  //при положение, че имаме методи за добавяне и премахване на елементи
  //  Beerhouse();
  //  const Beer* getBeers() const;
  //  void setBeers(const Beer*);
    void addBeer(const Beer&);
    const Beer& sellBeer(const char*,double);
    void print() const;
    bool isEmpty() const;

};