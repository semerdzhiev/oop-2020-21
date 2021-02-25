#include <cassert>
#include <iostream>

// dynamic array with a specified capacity and with certain number of elements (size)

// allocate the memory
// think about why the input argument for the array is of type int*&?
void allocateMemory(int*& array, size_t capacity)
{
    array = new (std::nothrow) int[capacity] {};
}

// delete the allocated memory
void freeMemory(int*& array, size_t& size, size_t& capacity)
{
    delete [] array;

    array = nullptr;
    size = 0;
    capacity = 1;
}

// reallocate memory with different capacity
bool reallocateMemory(int*& array, size_t size, size_t newCapacity)
{
    int* temp = new (std::nothrow) int[newCapacity] {};

    if(!temp)
        return false;

    for(size_t i = 0; i < size; ++i)
    {
        // copy the existing elements
        temp[i] = array[i];
    }

    // delete the current memory
    delete [] array;

    // trasfer the pointer to the new memory
    array = temp;

    return true;
}

// resize the array, if necessary
// double the size
bool resize(int*& array, size_t size, size_t& capacity)
{
    if(size == capacity)
    {
        capacity = (0 == capacity)? 1 : 2*capacity;

        return reallocateMemory(array, size, capacity);
    }

    return true;
}

// add element at the end of the array
// if the size is less than the capacity, the array should be resized
// resize the array, if necessary
bool addElement(int*& array, size_t& size, size_t& capacity, int newElem)
{
    // check for correct input arguments
    assert(array);
    assert(size <= capacity);

    // if neccessary, resize the array
    if(resize(array, size, capacity))
    {
        // the element is stored at the end
        array[size] = newElem;
        ++size;

        return true;
    }

    // if the attempt to resize the array has failed
    return false;
}

// add element at a specified position of the array
// resize if necessary
bool addElement(int*& array, size_t& size, size_t& capacity, int newElem, size_t position)
{
    // check if the input arguments are correct
    assert(array);
    assert(size <= capacity);

    if(position > size)
    {
        std::cout << "The new element cannot be added to the specified positon! \n";
        return false;
    }

    // if the capacity of the array has been reached, 
    // resize the array, double the capacity
    if(resize(array, size, capacity))
    {
        // move to the right all elements, 
        // stored after the specified position
        for(size_t i = size; i > position; --i)
        {
            array[i] = array[i - 1];
        }

        array[position] = newElem;
        ++size;

        return true;
    }

    // if the attempt to resize the array has failed
    return false;
}

// print the elements of the array
void print(const int* array, size_t size, size_t capacity)
{
    // check if the values of the input arguments are valid
    assert(array);
    assert(size <= capacity);

    std::cout << "The elements in the array are: ";

    for(size_t i = 0; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }

    std::cout << std::endl;
}

// remove the element at the specified position
// if the number of elements are less than 1/4 of the capacity,
// resize the array, use half of its capacity
bool removeElement(int*& array, size_t& size, size_t& capacity, size_t position)
{
    // check the values of the input arguments
    assert(array);
    assert(size <= capacity);

    if(position > size)
    {
        std::cout << "There is no element at the specified positon! \n";
        return false;
    }

    // what if there are no elements at all?
    if(!size) return true;

    // shift left all elements stored after the specified position
    for(size_t i = position + 1; i < size; ++i)
    {
        array[i - 1] = array[i];
    }

    -- size;

    // if the actual number of elements in the array
    // is not more than 1/4 of the capacity,
    // the capacity should be reduced twice
    if(size <= capacity / 4)
    {
        // намаляваме капацитета наполовина
        capacity /= 2;

        reallocateMemory(array, size, capacity);
    }

    return true;
}

int main()
{
    // dynamic array that can be resized
    int* array{ nullptr };

    // capacity of the array
    size_t capacity = 3;

    // exact number of elements in the array
    size_t size = 0;

    allocateMemory(array, capacity);

    addElement(array, size, capacity, 1);
    addElement(array, size, capacity, 2);
    addElement(array, size, capacity, 3);

    std::cout << "The capacity of the array is " << capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << size << std::endl;
    print(array, size, capacity);

    addElement(array, size, capacity, 4, 2);

    std::cout << "\nThe capacity of the array is " << capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << size << std::endl;
    print(array, size, capacity);

    removeElement(array, size, capacity, 0);
    removeElement(array, size, capacity, 0);
    removeElement(array, size, capacity, 0);

    std::cout << "\nThe capacity of the array is " << capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << size << std::endl;

    print(array, size, capacity);

    freeMemory(array, size, capacity);

    return 0;
}
