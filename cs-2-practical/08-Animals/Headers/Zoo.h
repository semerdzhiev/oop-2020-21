#pragma once
#include "Fauna.h"
class Zoo {
private:
	AnimalFamily** animalFamilies = nullptr;
	const unsigned capacity = 0;
	unsigned numOfAnimals = 0;
	unsigned numOfFamilies = 0;

	int findFamily(const char* name);

public:
	explicit Zoo(unsigned int capacity);
	Zoo(const Zoo& other);
	Zoo(Zoo&& other) noexcept;
	Zoo& operator=(const Zoo& other)=delete;
	~Zoo();

	void addFamily(const char* name, unsigned number);
	void addFamily(AnimalFamily& newFamily);
	AnimalFamily* removeFamily(const char* name);
	AnimalFamily* removeFamily(const AnimalFamily& newFamily);
	void print(std::ostream& os) const;
    [[nodiscard]] const AnimalFamily* at(unsigned pos) const;
};