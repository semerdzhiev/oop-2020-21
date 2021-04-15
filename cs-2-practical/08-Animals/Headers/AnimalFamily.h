#pragma once
#include <iostream>

class AnimalFamily {
private:

	char* name=nullptr;
	unsigned int number=0;

	void copyFrom(const AnimalFamily& other);
public:
	//AnimalFamily()
	AnimalFamily(const char* newName, unsigned int newNum);
	AnimalFamily(const AnimalFamily& other);
	AnimalFamily& operator=(const AnimalFamily& other);
	AnimalFamily(AnimalFamily&& other) noexcept;
	AnimalFamily& operator=(AnimalFamily&& other) noexcept;

	~AnimalFamily();

	const char* getName() const;
	unsigned int getNumber() const;
	void print(std::ostream& os) const;

};