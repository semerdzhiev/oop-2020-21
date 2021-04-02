#include <cstring>
#include "horo.h"

ImmutableHoro::ImmutableHoro(char *name, char *meter, char *region)
{
    this->name = new (std::nothrow) char[strlen(name) + 1];
    strcpy(this->name, name);
    this->name[strlen(name)] = '\0';

    this->meter = new (std::nothrow) char[strlen(meter) + 1];
    strcpy(this->meter, meter);
    this->meter[strlen(meter)] = '\0';

    this->region = new (std::nothrow) char[strlen(region) + 1];
    strcpy(this->region, region);
    this->region[strlen(region)] = '\0';
}

const char *ImmutableHoro::getName()
{
    return name;
}

const char *ImmutableHoro::getMeter()
{
    return meter;
}

const char *ImmutableHoro::getRegion()
{
    return region;
}

ImmutableHoro::~ImmutableHoro() {
    delete[] name;
    delete[] meter;
    delete[] region;
}