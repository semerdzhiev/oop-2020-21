#pragma once
#include<iostream>

class ToFile{
public:
    virtual void toFile(std::ofstream& os) const =0;
};