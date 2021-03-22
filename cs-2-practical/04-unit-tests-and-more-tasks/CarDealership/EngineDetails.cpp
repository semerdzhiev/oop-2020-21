#include "EngineDetails.h"
#include<iostream>
using std::cin;
using std::cout;


EngineDetails::EngineDetails(unsigned int _hp, double vol, EngineType et) : horsePower(_hp), volume(vol), engineType(et) {}

void EngineDetails::print() const {
    cout<<"Horse power:"<<horsePower<<"\nVolume:"<<volume<<"\nEngine type:"<<static_cast<std::underlying_type<EngineType>::type>(engineType)<<'\n';
}

void EngineDetails::readFromConsole() {
    cin>>horsePower>>volume;
    scanf("%d",&engineType);
}