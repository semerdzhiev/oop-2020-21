#pragma once

class Person
{

private:
	char* m_name;
	char* m_address;
	int m_age;
	bool m_hasDrivingLicense;

	void erase();

	void copy(const Person& p);

public:
	Person(const char* name = "N/A",
		const char* adrress = "N/A",
		const int age = 20,
		const bool hasDrivingLicense = false);

	Person(const Person& p);

	Person& operator=(const Person& other);

	void setName(const char* name);

	void setAddress(const char* address);

	void setAge(const int age);

	void setHasDrivingLicense(const bool hasDrivingLicense);

	char* getName() const;

	char* getAddress() const;

	int getAge() const;

	bool getHasDrivingLicense() const;

	void print();

	~Person();
};
