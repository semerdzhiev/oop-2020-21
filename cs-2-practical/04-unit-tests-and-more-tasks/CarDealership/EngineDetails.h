#pragma once
enum class EngineType {
    Unknown = -1,
    Diesel = 0,
    Petrol,
    Hybrid,
    Electric
};



struct EngineDetails {
    unsigned int horsePower;
    double volume;
    EngineType engineType;

    EngineDetails(unsigned int _hp=0,double vol=0,EngineType et=EngineType::Unknown);

    void print() const;
    void readFromConsole();
};