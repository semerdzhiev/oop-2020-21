#include "Person.h"
#include "Utils.h"
#include <iostream>


Person::Person(const char* name,
	const char* adrress,
	const int age,
	const bool hasDrivingLicense) {
	m_age = age;
	m_hasDrivingLicense = hasDrivingLicense;
	m_name = copyDynStr(name);
	m_address = copyDynStr(adrress);
}

Person::Person(const Person& p) {
	copy(p);
}

Person& Person::operator=(const Person& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

void Person::setName(const char* name) {
	delete[] m_name;
	m_name = copyDynStr(name);
}

void Person::setAddress(const char* address) {
	delete[] m_address;
	m_address = copyDynStr(address);
}

void Person::setAge(const int age) {
	m_age = age;
}

void Person::setHasDrivingLicense(const bool hasDrivingLicense) {
	m_hasDrivingLicense = hasDrivingLicense;
}

char* Person::getName() const {
	return m_name;
}

char* Person::getAddress() const {
	return m_address;
}

int Person::getAge() const {
	return m_age;
}

bool Person::getHasDrivingLicense() const {
	return m_hasDrivingLicense;
}

void Person::erase() {
	delete[] m_name;
	delete[] m_address;
}

void Person::copy(const Person& p) {
	m_name = copyDynStr(p.m_name);
	m_address = copyDynStr(p.m_address);
	m_age = p.m_age;
	m_hasDrivingLicense = p.m_hasDrivingLicense;
}

Person::~Person() {
	erase();
}

void Person::print() {
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Address: " << m_address << std::endl;
	std::cout << "Age: " << m_age << std::endl;
	std::cout << "HasDrivingLicense: " << m_hasDrivingLicense << std::endl;
}
