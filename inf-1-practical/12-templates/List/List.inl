#include <cassert>
#include <iostream>
#include "List.h"


template<typename T>
List<T>::List(T *arr, size_t size) {
    this->capacity = size;
    this->size = size;

    this->arr = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        this->arr[i] = arr[i];
    }
}

template<typename T>
List<T>::List(const List<T> &rhs) {
    capacity = rhs.capacity;
    size = rhs.size;

    arr = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rhs.arr[i];
    }
}

template<typename T>
List<T>::~List() {
    delete [] arr;
}

template<typename T>
size_t List<T>::getCapacity() const {
    return capacity;
}

template<typename T>
size_t List<T>::getSize() const {
    return size;
}

template<typename T>
T &List<T>::operator[](size_t idx) {
    assert(idx < size);
    return arr[idx];
}

template<typename T>
void List<T>::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
List<T> List<T>::filter(bool (*func)(T)) {
    T* temp = new T[size];
    size_t sz = 0;

    for (size_t i = 0; i < size; ++i) {
        if (func(arr[i])) {
            temp[sz] = arr[i];
            ++sz;
        }
    }

    List<T> result(temp, sz);
    delete [] temp;

    return result;
}

template<typename T>
template<typename F>
List<T> List<T>::genFilter(F f) {
    T* temp = new T[size];
    size_t sz = 0;

    for (size_t i = 0; i < size; ++i) {
        if (f(arr[i])) {
            temp[sz] = arr[i];
            ++sz;
        }
    }

    List<T> result(temp, sz);
    delete [] temp;

    return result;
}

template<typename T>
template<typename T2>
List<T2> List<T>::map(T2 (*func)(T)) {
    T* temp = new T[size];

    for (size_t i = 0; i < size; ++i) {
        temp[i] = func(arr[i]);
    }

    List<T> result(temp, size);
    delete [] temp;

    return result;
}

template<typename T>
T List<T>::reduce(T (*func)(T, T), T init) {
    if (size == 0) return init;

    T result = func(arr[0], init);

    for (size_t i = 1; i < size; ++i) {
        result = func(arr[i], result);
    }

    return result;
}

template<typename T>
void List<T>::add(T &elem) {
    if (size == capacity) {
        throw std::exception();
    }

    arr[size++] = elem;
}

template<typename T>
bool List<T>::remove(T &elem) {
    if (size == 0) return false;

    size_t idx = 0;
    bool found = false;

    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == elem) {
            idx = i;
            found = true;
            break;
        }
    }

    if (!found) {
        return false;
    }

    return remove(idx);
}

template<typename T>
bool List<T>::remove(size_t idx) {
    if (idx > size) return false;

    for (size_t i = idx; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size -= 1;

    return true;
}

template<typename T>
bool List<T>::contains(T &elem) const {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == elem) {
            return true;
        }
    }
    return false;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const List<T>& list) {
    for (size_t i = 0; i < list.size; ++i) {
        out << list.arr[i] << " ";
    }
    out << std::endl;
    return out;
}
