#pragma once
class Vector
{
private:
	size_t size;
	int* arr;
public:
	//To create big 4...
	Vector();
	Vector(size_t n);
	Vector(const Vector& obj);
	~Vector();
	Vector& operator=(const Vector& obj);
	void putValue(int position, int el);
	int getValue(int position) const;
	size_t getSize() const;
	void add(const Vector& obj);
	Vector  operator+ (Vector const& obj);
	Vector& operator+= (Vector const& obj);
	Vector  operator* (int mult); // To be implemented
	Vector& operator*= (int mult); // To be implemented
	const int& operator[](size_t idx) const;
	int& operator[](size_t index);
	bool operator==(Vector const& obj);
};

