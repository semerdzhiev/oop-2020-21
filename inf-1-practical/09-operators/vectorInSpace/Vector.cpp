
#include <iostream>
#include <cmath>
#include <cassert>

#include "Vector.h"

Vector::Vector(std::size_t size) : dim(size) {
    vec = new int[dim];

    for (int i = 0; i < dim; ++i) {
        vec[i] = 0;
    }

}

Vector::Vector(std::size_t size, int *vec) : dim(size) {
    this->vec = new int[dim];

    for (int i = 0; i < dim; ++i) {
        this->vec[i] = vec[i];
    }
}

Vector::Vector(int x, int y) : dim(2) {
    vec = new int[dim];

    vec[0] = x;
    vec[1] = y;
}

Vector::Vector(int x, int y, int z) : dim(3) {
    vec = new int[dim];

    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

Vector::Vector(const Vector &rhs) : Vector(rhs.dim, rhs.vec) {
}

Vector &Vector::operator=(const Vector &rhs) {
    if (this != &rhs) {
        delete [] vec;
        dim = rhs.dim;

        vec = new int[dim];

        for (int i = 0; i < dim; ++i) {
            vec[i] = rhs.vec[i];
        }
    }

    return *this;
}

Vector::~Vector() {
    delete [] vec;
}

void Vector::sum(const Vector &other) {
    std::size_t size = dim > other.dim ? other.dim : dim;

    for (int i = 0; i < size; ++i) {
        vec[i] += other.vec[i];
    }
}

void Vector::scalar(int k) {
    for (int i = 0; i < dim; ++i) {
        vec[i] *= k;
    }
}

int Vector::dotProduct(const Vector &other) const {
    int result = 0;

    std::size_t size = dim > other.dim ? other.dim : dim;

    for (int i = 0; i < size; ++i) {
        result += vec[i] * other.vec[i];
    }

    return result;
}

std::size_t Vector::size() const {
    return dim;
}

void Vector::resize(std::size_t size) {
    int *temp = new int[size];

    std::size_t n = dim > size ? size : dim;

    for (int i = 0; i < n; ++i) {
        temp[i] = vec[i];
    }

    if (size > dim) {
        for (int i = n; i < size; ++i) {
            temp[i] = 0;
        }
    }

    delete [] vec;
    vec = temp;
}

void Vector::print() const {
    std::cout << "Vector ( ";

    for (int i = 0; i < dim; ++i) {
        std::cout << vec[i] << " ";
    }

    std::cout << ")\n";
}

Vector Vector::operator+(const Vector &rhs) const {
    Vector v(*this);

    v.sum(rhs);

    return v;
}

Vector &Vector::operator+=(const Vector &rhs) {
    sum(rhs);

    return *this;
}

Vector Vector::operator-(const Vector &rhs) const {
    Vector v(*this);

    // TODO: implement sub()

    return v;
}

Vector &Vector::operator-=(const Vector &rhs) {
    // TODO: call sub(rhs)

    return *this;
}

Vector &Vector::operator++() {
    for (int i = 0; i < dim; ++i) {
        vec[i] += 1;
    }

    return *this;
}

Vector Vector::operator++(int) {
    Vector v = *this;

    ++(*this);
    return v;
}

std::istream &operator>>(std::istream& in, Vector &vector) {
    for (int i = 0; i < vector.dim; ++i) {
        in >> vector.vec[i];
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const Vector &vector) {
    out << "Vector ( ";

    for (int i = 0; i < vector.dim; ++i) {
        out << vector.vec[i] << " ";
    }

    out << ")";

    return out;
}

Vector::operator bool() const {
    for (int i = 0; i < dim; ++i) {
        if (vec[i] != 0) {
            return false;
        }
    }

    return true;
}

Vector::operator double() const {
    return sqrt(dotProduct(*this));
}

Vector Vector::operator*(int k) const {
    Vector v = *this;
    v.scalar(k);

    return v;
}

Vector &Vector::operator*=(int k) {
    scalar(k);

    return *this;
}

int Vector::operator[](std::size_t index) const {
    assert(index < dim);

    return vec[index];
}

bool Vector::operator<(const Vector &rhs) const {
    std::size_t size = dim > rhs.dim ? rhs.dim : dim;
    std::size_t cnt = 0;

    for (int i = 0; i < size; ++i) {
        if (vec[i] > rhs.vec[i]) {
            return false;
        } else if (vec[i] == rhs.vec[i]) {
            ++cnt;
        }
    }

    return cnt != size;
}

bool Vector::operator>(const Vector &rhs) const {
    return rhs < *this;
}

bool Vector::operator<=(const Vector &rhs) const {
    return !(*this > rhs);
}

bool Vector::operator>=(const Vector &rhs) const {
    return !(*this < rhs);
}

bool Vector::operator==(const Vector &rhs) const {
    if (dim != rhs.dim) {
        return false;
    }

    for (int i = 0; i < dim; ++i) {
        if (vec[i] != rhs.vec[i]) {
            return false;
        }
    }

    return true;
}

bool Vector::operator!=(const Vector &rhs) const {
    return !(*this == rhs);
}






