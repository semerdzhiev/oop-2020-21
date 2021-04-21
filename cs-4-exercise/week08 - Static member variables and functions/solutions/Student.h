#pragma once
class Student
{

private:
	char* m_name = nullptr;
	int m_facultyNumber;
	bool m_hasSubject;

	void erase();

	void copy(const Student& other);

public:

	Student(const char* m_name, int m_facultyNumber, bool m_hasSubject);

	Student(const Student& other);

	Student& operator=(const Student& other);

	~Student();

	void print();

	void setHasSubject(bool hasSubject);

	bool hasSubject() const;

};

