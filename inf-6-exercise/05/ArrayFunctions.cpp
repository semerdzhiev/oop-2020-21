#include "ArrayFunctions.h"

#include <cassert>
#include <iostream>

void allocateMemory(Array& array)
{
    array.capacity = 1;
    array.data = new (std::nothrow) int[array.capacity];
    array.size = 0;
}

void freeMemory(Array& array)
{
    delete [] array.data;

    array.data = nullptr;
    array.size = 0;
    array.capacity = 1;
}

bool resize(Array& array)
{
    if(array.size == array.capacity)
    {
        size_t newCapacity = (0 == array.capacity)? 1 : 2 * array.capacity;

        int* temp = new (std::nothrow) int[newCapacity];

        if (!temp)
            return false;

        for (size_t i = 0; i < array.size; ++i)
        {
            temp[i] = array.data[i];
        }

        delete[] array.data;
        array.data = temp;
        array.capacity = newCapacity;
    }

    return true;
}

bool addElement(Array& array, int newElem)
{
    if(!array.data || array.size > array.capacity)
        return false;

    if(resize(array))
    {
        array.data[array.size] = newElem;
        ++array.size;

        return true;
    }

    return false;
}

bool addElement(Array& array, int newElem, size_t position)
{
    if (!array.data || array.size > array.capacity)
        return false;

    if(position > array.size)
    {
        std::cout << "The new element cannot be added to the specified positon! \n";
        return false;
    }

    if(resize(array))
    {
        for(size_t i = array.size; i > position; --i)
        {
            array.data[i] = array.data[i - 1];
        }

        array.data[position] = newElem;
        ++array.size;

        return true;
    }

    return false;
}

void print(const Array& array)
{
    if (!array.data || array.size > array.capacity)
        return;

    std::cout << "The elements in the array are: ";

    for(size_t i = 0; i < array.size; ++i)
    {
        std::cout << array.data[i] << ' ';
    }

    std::cout << std::endl;
}

bool removeElement(Array& array, size_t position)
{
    // write the test first then do the changes in the function
    if (!array.data)
        return false;

    // array.data != nullptr
    if (array.size == 0)
        return false;

    if (position >= array.size)
        return false;

    for(size_t i = position + 1; i < array.size; ++i)
    {
        array.data[i - 1] = array.data[i];
    }

    -- array.size;

    return true;
}
