#pragma once
#include "Utils.h"

class Person
{

private:
	char* m_name;
	char* m_address;
	int m_age;
	bool m_hasDrivingLicense;

	void erase();

public:
	Person(const char* name = "N/A",
		 const char* adrress = "N/A",
		 const int age = 20,
		 const bool hasDrivingLicense = false);

	void setName(const char* name);

	char* getName() const;

	~Person();
};

