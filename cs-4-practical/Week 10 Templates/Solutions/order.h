#pragma once
#include <iostream>
#include "list.h"

template <typename T>
class Order : public List<T>
{
    using List<T>::items;
    using List<T>::count;
    using List<T>::capacity;
    using List<T>::resize;
    using List<T>::isEmpty;

    void sort();

public:
    Order() : List<T>::List(){};
    void add(T const &);
};

template <typename T>
void Order<T>::sort() {
    for(int i = 0; i < count; i++) {
        for(int j = i+1; j < count; j++) {
            if(items[i] > items[j]) {
                T temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

template <typename T>
void Order<T>::add(T const &temp) {
    for (int i = 0; i < count; i++)
    {
        if (items[i] == temp)
        {
            return;
        }
    }

    count++;

    if (count == capacity)
    {
        resize();
    }

    if (isEmpty()) {
        List<T>::items[count] = temp;
    } else {
        for (int i = count - 1; i > 0; i--) {
            if (temp > List<T>::items[i - 1]) {
                List<T>::items[i] = temp;
                break;
            } else {
                List<T>::items[i] = List<T>::items[i - 1];
            }
        }
    }
}
