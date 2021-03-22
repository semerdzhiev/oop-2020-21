#pragma once

#define CURRENT_YEAR 2020
#define CAR_FIRST_YEAR 1885

class ManufactureDetails {
    char* name;
    char* model;
    unsigned int year;

public:
    ManufactureDetails();
    ManufactureDetails( const char*, const char*, unsigned int );
    ManufactureDetails( const ManufactureDetails& );
    ManufactureDetails& operator=( const ManufactureDetails& );
    ~ManufactureDetails();

    void print() const;
    void readFromConsole();
private:
    void init( const char*, const char*, unsigned int );
    void clean();
    void create(const char*, const char*);
};