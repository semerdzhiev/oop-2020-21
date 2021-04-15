#pragma once
#include "Zoo.h"

class Planet {
private:
	Zoo* zoos;
	Fauna* faunas;

public:
	Planet(unsigned zooCapacity,unsigned faunaCapacity);
	~Planet();
	Planet(const Planet&) = delete;
	Planet& operator=(const Planet&) = delete;

	void addFamilyZoo(const AnimalFamily& newFamily);
	void addFamilyZoo(const char* name, unsigned number);
	void addFamilyFauna(const AnimalFamily& newFamily);
	void addFamilyFauna(const char* name, unsigned number);
	void removeFamilyZoo(const AnimalFamily& newFamily);
	void removeFamilyFauna(const AnimalFamily& newFamily);
    void removeFamilyZoo(const char* name);
    void removeFamilyFauna(const char* name);
	void print(std::ostream& os) const ;

};