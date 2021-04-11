#pragma once

class AnimalFamily 
{
private:

    char* name{};
    unsigned nameLen{};
    unsigned members{};

public:
    
    AnimalFamily(const char*, unsigned);
    AnimalFamily(const AnimalFamily&);
    AnimalFamily& operator=(const AnimalFamily&);
    ~AnimalFamily();

    const char* getName() const;
    unsigned getMembers() const;
    void print() const;
};  
