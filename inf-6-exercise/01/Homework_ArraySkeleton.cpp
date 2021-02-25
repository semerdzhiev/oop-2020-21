#include <cassert>
#include <iostream>

// dynamic array with a specified capacity and with certain number of elements (size)

// please consider why the input argument for the array is of type int*&?
// create a header file with the declarations of the functions,
// move the definitions to a .cpp file
// show how they are used in main.cpp

// allocate the memory
void allocateMemory(int*& array, size_t capacity)
{
    
}

// delete the allocated memory
void freeMemory(int*& array, size_t& size, size_t& capacity)
{
    
}

// reallocate memory with different capacity
bool reallocateMemory(int*& array, size_t size, size_t newCapacity)
{
    
}

// resize the array, if necessary
// double the size
bool resize(int*& array, size_t size, size_t& capacity)
{
 
}

// add element at the end of the array
// if the size is less than the capacity, the array should be resized
// resize the array, if necessary
bool addElement(int*& array, size_t& size, size_t& capacity, int newElem)
{

}

// add element at a specified position of the array
// resize if necessary
bool addElement(int*& array, size_t& size, size_t& capacity, int newElem, size_t position)
{

}

// print the elements of the array
void print(const int* array, size_t size, size_t capacity)
{
 
}

// remove the element at the specified position
// if the number of elements are less than 1/4 of the capacity,
// resize the array, use half of its capacity
bool removeElement(int*& array, size_t& size, size_t& capacity, size_t position)
{

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
