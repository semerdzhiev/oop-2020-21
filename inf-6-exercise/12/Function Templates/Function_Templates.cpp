#include "Function Templates/ComplexNumbers (Operators overloading)/ComplexNumber.h"

#include <cstring>
#include <iostream>

// FUNCTION TEMPLATES

// check if a certain element is in the array
bool isElementIn(int* arr, size_t n, int numberToFind)
{
    for(size_t i = 0; i < n; ++i)
    {
        if(arr[i] == numberToFind)
            return true;
    }

    return false;
}

// how to transfer this into a template of a function?
// int -> T, but not every int! Be careful of the meaning...
template <typename T>
bool isElementIn(const T* arr, size_t n, const T& numberToFind)
{
    for (size_t i = 0; i < n; ++i)
    {
        // operator == should be defined for the type T
        // what happens if the relation < is changed with something else?
        if (arr[i] == numberToFind)
        {
            return true;
        }
    }

    return false;
}

template <typename T>
size_t findIndexOfMin(const T* arr, size_t n)
{
    size_t indexMin = 0;
    for (size_t i = 1; i < n; ++i)
    {
        // operator < should be defined for the type T
        // what happens if the relation < is changed with something else?
        if (arr[i] < arr[indexMin])
        {
            indexMin = i;
        }
    }

    return indexMin;
}

template <typename T>
void swap(T& a, T& b)
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

// print the elements of the array
template <typename T>
void print(T* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        // operator << should be defined for the type T
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

// specialization for the type char
void print(char* str, size_t n)
{
    std::cout << str << std::endl;
}

template<typename T, typename U = T>
U sum(const T& a, const U& b)
{
    U result = a + b;
    return result;
}

int main()
{
    const int n = 6;
    int arr[] = {5, 0, 1, 1, 4, 7};
    std::cout << "Array: ";
    print(arr, n);

    std::cout << "Is 3 an element of the array? " << std::boolalpha << isElementIn(arr, n, 3) << std::endl;
    std::cout << "Is 7 an element of the array? " << std::boolalpha << isElementIn(arr, n, 7) << std::endl;

    char str[] = "abcd";
    print(str, strlen(str));

    std::string a = "a";
    std::string b = "b";
    std::cout << "Swaped? " << a << ' ' << b << std::endl;

    ComplexNumber x(5, 2);
    double y = 7;

    // ComplexNumber + double, what should be the type of the result?
    // T -> ComplexNumber
    // U -> double, ComplexNumber
    // compile error
    //std::cout << sum(x, y) << std::endl;

    // T -> double
    // U -> ComplexNumber
    std::cout << sum(y, x) << std::endl;

    //const int cnN = 3;
    //ComplexNumber cnArr[] = { {5, 3}, {2, 5}, {1, 0} };

    // ComplexNumber does not define operator <, error!
    //int indexOfMin = findIndexOfMin(cnArr, cnN);
    //std::cout << cnArr[indexOfMin] << std::endl;

    return 0;
}
