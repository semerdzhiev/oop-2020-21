#include "Person.h"
#include<cstring>
#include<iostream>
Person::Person(const char *name, const char *ucn) {
    std::cout<<"Person()\n";
    int sizeName = strlen(name);
    this->name = new char[sizeName];
    strcpy(this->name,name);

    int sizeUCN = strlen(ucn);
    this->ucn = new char[sizeUCN];
    strcpy(this->ucn,ucn);
}


Person::~Person() {
    delete[] name;
    delete[] ucn;
    std::cout<<"~Person()";
}

const char * Person::getName() const {
    return this->name;
}

const char *Person::getUCN() const {
    return this->ucn;
}