#ifndef HORO
#define HORO

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class ImmutableHoro {
    char* name;
    char* meter;
    char* region;

public:
    ImmutableHoro(char *name, char *meter, char *region);
    
    const char *getName(); // const return type
    const char *getMeter(); // const return type
    const char *getRegion(); // const return type

    // no setters

    ~ImmutableHoro();
};

#endif