#include <exception>
#include <iostream>

template <typename T>
class Vector {

    T* data;
    int size;
    int capacity;

    void clean() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    void copy(const Vector& other, bool doClean = true) {
        if (doClean) {
            clean();
        }

        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

public:

    Vector(int capacity = 10) : size(0), capacity(capacity) {
        data = new T[capacity];
    }

    Vector(const Vector& other) {
        copy(other, false);
    }

    ~Vector() {
        clean();
    }

    Vector& operator=(const Vector& other) {
        if (&other != this) {
            copy(other);
        }

        return *this;
    }

    Vector operator+(const Vector& other) {
        Vector v(*this);

        for (int i = 0; i < other.size; ++i) {
            v.add(other.data[i]);
        }

        return v;
    }

    const int& operator[](int index) const {
        return getAt(index);
    }

    int& operator[](int index) {
        return getAt(index);
    }

    const int& getAt(int index) const {
        if (index > size - 1) {
            throw std::exception("out of bounds");
        }

        return data[index];
    }

    int& getAt(int index) {
        if (index > size - 1) {
            throw std::exception("out of bounds");
        }

        return data[index];
    }

    int getSize() const {
        return size;
    }

    void add(const int& newElement) {
        if (size + 1 > capacity || capacity == 0) {
            capacity = (capacity == 0) ? 8 : capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = newElement;
    }

    void print(std::ostream& out) const {
        for (int i = 0; i < size; ++i) {
            out << data[i]<< " ";
        }
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v) {
    v.print(out);
    return out;
}