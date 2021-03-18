#pragma once 

const unsigned MAX_BRAND_LENGTH = 127;
const unsigned MAX_VOLUME = 1000;
const unsigned MIN_VOLUME = 330;
const unsigned MIN_ABV = 4;
const unsigned MAX_ABV = 6;


class Beer 
{
private:

    char brand[MAX_BRAND_LENGTH];
    double abv; // Alcohol by volume
    unsigned volume;

public:

    Beer();
    Beer(char[], double, unsigned);
    void setBrand(char[]);
    void setAbv(double);
    void setVolume(unsigned);
    const char* getBrand() const;
    double getAbv() const;
    unsigned getVolume() const;
    void print() const;
};