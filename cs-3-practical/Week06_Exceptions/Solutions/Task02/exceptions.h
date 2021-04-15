#pragma once

#include <exception>

class VolumeOverflow : public std::exception
{
public:
    const char *what() const throw()
    {
        return "There is no more space in the backpack";
    }
};

class WeightOverflow : public std::exception
{
public:    
    const char *what() const throw()
    {
        return "The backpack will be to heavy";
    }
};