#pragma once
#include "EngineDetails.h"
#include "ManufactureDetails.h"
#include "VisualDetails.h"


class Car {
    EngineDetails engineDetails;
    VisualDetails visualDetails;
    ManufactureDetails manufactureDetails;
    bool isNew;
    unsigned int price;

public:
    Car();
    Car(const EngineDetails& ed, const VisualDetails& vd, const ManufactureDetails& md, bool _isNew,
        unsigned int price);
    Car(unsigned int horsePower, double volume, EngineType type, unsigned int doorCount,
        bool hasWing, const char* color, const char* name, const char* model, unsigned int year,
        bool isNew, unsigned int price);
    ~Car();

    void print() const;
    void readFromConsole();
};