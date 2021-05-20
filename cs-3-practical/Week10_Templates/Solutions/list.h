#pragma once
#include <iostream>
#include <fstream>

template <typename T>
class List {
    void copy(List const &);

protected:
    T* items;
    int capacity;
    int count;
    void resize();

public:
    List();
    List(List const &);

    bool isEmpty();
    int size();
    void add(T const &);
    void remove(int);
    void read(char *fileName);
    void save(char *fileName);

    List &operator=(List const &);
    T &operator[](int);

    ~List();
};

template <typename T>
void List<T>::copy(List const &temp)
{
    delete[] items;

    capacity = temp.capacity;
    count = temp.count;
    items = new T[capacity];

    for(int i=0; i<count; ++i) {
        items[i] = temp.items[i];
    }
}

template <typename T>
void List<T>::resize()
{
    capacity *= 2;
    T* newData = new T[capacity];
    for(int i = 0; i < count; i++) {
        newData[i] = items[i];
    }
    delete[] items;
    items = newData;
}

template <typename T>
List<T>::List()
{
    capacity = 8;
    items = new T[capacity];
    count = 0;
}

template <typename T>
List<T>::List(List const &temp)
{
    copy(temp);
}

template <typename T>
List<T>::~List()
{
    delete[] items;
}

template <typename T>
List<T> &List<T>::operator=(List const &temp)
{
    if (this != &temp) {
        copy(temp);
    }
    return *this;
}

template <typename T>
T &List<T>::operator[](int i)
{
    return items[i];
}

template <typename T>
bool List<T>::isEmpty()
{
    return !count;
}

template <typename T>
int List<T>::size()
{
    return count;
}

template <typename T>
void List<T>::add(T const &temp)
{
    for(int i = 0; i < count; i++) {
        if(items[i] == temp) {
            return;
        }
    }

    if(count == capacity) {
        resize();
    }

    items[count++] = temp;
}

template <typename T>
void List<T>::remove(int ind)
{
    if(ind < count) {
        count--;
        for(int i=ind; i<count; ++i) {
            items[i] = items[i+1];
        }
    }
}

template <typename T>
void List<T>::save(char *fileName) {
    std::ofstream out(fileName);
    out << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        out << items[i] << std::endl;
    }
}

template <typename T>
void List<T>::read(char *fileName)
{
    std::ifstream in(fileName);
    int cnt;
    in >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        T tmp;
        in >> tmp;
        add(tmp);
    }
}