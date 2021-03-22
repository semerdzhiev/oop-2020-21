#include "ManufactureDetails.h"
#include<cstring>
#include <new>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

ManufactureDetails::ManufactureDetails() {
    init("","",1885);
}

ManufactureDetails::ManufactureDetails(const char* _name, const char* _model, unsigned int _year) {
    create(_name, _model);
    init(_name,_model,_year);
}

void ManufactureDetails::create(const char* _name, const char* _model) {
    try{
        name = new char[strlen(_name)+1];
    } catch (const std::bad_alloc& ex) {
        std::cerr<<ex.what()<<'\n';
        exit(1);
    }

    try{
        model = new char[strlen(_model)+1];
    } catch (const std::bad_alloc& ex) {
        std::cerr<<ex.what()<<'\n';
        exit(1);
    }
}

ManufactureDetails::ManufactureDetails(const ManufactureDetails &other) {
    create(other.name, other.model);
    init(other.name,other.model,other.year);
}

ManufactureDetails & ManufactureDetails::operator=(const ManufactureDetails &other) {
    if(this !=&other) {
        clean();
        create(other.name,other.model);
        init(other.name,other.model,other.year);
    }
    return *this;
}

ManufactureDetails::~ManufactureDetails() {
    clean();
}

void ManufactureDetails::print() const {
    cout<<name<<endl<<model<<year;
}

void ManufactureDetails::clean() {
    delete[] name;
    delete[] model;
    year=0;
}

void ManufactureDetails::init(const char* name, const char* model, unsigned int year) {

}