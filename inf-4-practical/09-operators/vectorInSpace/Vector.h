#pragma once

#include <cstddef>

class Vector {
public:
    explicit Vector(std::size_t size);
    Vector(std::size_t size, int *vec);
    Vector(int x, int y);
    Vector(int x, int y, int z);
    Vector(const Vector& rhs);
    Vector& operator=(const Vector& rhs);
    ~Vector();

    void sum(const Vector& other);
    void scalar(int k);
    int dotProduct(const Vector& other) const;
    std::size_t size() const;
    void resize(std::size_t size);
    void print() const;

    Vector operator+(const Vector& rhs) const;
    Vector& operator+=(const Vector& rhs);
    Vector operator-(const Vector& rhs) const;
    Vector& operator-=(const Vector& rhs);

    Vector& operator++();   // ++i
    Vector operator++(int); // i++;

    friend std::istream& operator>>(std::istream&, Vector& vector);
    friend std::ostream& operator<<(std::ostream&, const Vector& vector);

    operator bool() const;
    operator double() const;

    Vector operator*(int k) const;
    Vector& operator*=(int k);

    int operator[](std::size_t index) const;

    bool operator<(const Vector& rhs) const;
    bool operator>(const Vector& rhs) const;
    bool operator<=(const Vector& rhs) const;
    bool operator>=(const Vector& rhs) const;
    bool operator==(const Vector& rhs) const;
    bool operator!=(const Vector& rhs) const;

private:
    int *vec;
    std::size_t dim;
};
