#pragma once
#include "AnimalFamily.h"


class Fauna {
private:
	AnimalFamily** animalFamilies=nullptr;
	const unsigned capacity=0; //max number of animals
	unsigned numOfAnimals = 0;
	unsigned numOfFamilies = 0;

	static int findFamily(const char* name, AnimalFamily** family, unsigned numOfFamilies);


public:

	explicit Fauna(unsigned capacity);
	Fauna(const Fauna& other);
	Fauna(Fauna&& other) noexcept;
	Fauna& operator=(const Fauna&)=delete;
	Fauna& operator=(Fauna&&) = delete;
	~Fauna();
	void addFamily(const char* name, unsigned number);
	void addFamily(const AnimalFamily& newFamily);
	void removeFamily(const char* name);
	void removeFamily(const AnimalFamily& newFamily);
	void print(std::ostream& os) const;
    int find(const char* name);

    [[nodiscard]] const AnimalFamily* at(unsigned pos) const;

	friend class Zoo;
};