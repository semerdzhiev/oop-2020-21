#include "Person.h"
#include "Utils.h"


Person::Person(const char* name,
				const char* adrress,
				 const int age,
				 const bool hasDrivingLicense) {
	m_age = age;
	m_hasDrivingLicense = hasDrivingLicense;
	m_name = copyDynStr(name);
	m_address = copyDynStr(adrress);
}

void Person::setName(const char* name) {
	delete[] m_name;
	m_name = copyDynStr(name);
}

char* Person::getName() const {
	return m_name;
}

void Person::erase() {
	delete[] m_name;
	delete[] m_address;
}

Person::~Person() {
	erase();
}





