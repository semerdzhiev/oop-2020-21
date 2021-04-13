#include <iostream>

#include <cassert>
#include <vector>

// по какви различни начини обработваме възможни грешки във функциите?
int findFirstElement(const int* array, size_t size, int elem)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        if (array[i] == elem)
            return i;
    }

    // в случай, че елементът не е открит
    return -1;
}

// не се обработва случаят за y == 0
double divide(int x, int y)
{
    return static_cast<double>(x) / y;
}

// да се провери резултата от функцията, преди да се използва стойността на result
bool divide(int x, int y, double& result)
{
    if (0 == y)
        return false;

    result = static_cast<double>(x) / y;
    return true;
}

// прости примери за прихващане на изключение
int main()
{
    std::cout << "Point 1: Before the try block..." << std::endl;
    try
    {
        std::cout << "Point 2: Inside the try block, before the throw..." << std::endl;

        throw "Error"; // изключението е от тип символен низ

        std::cout << "Point 3: Inside the try block, after the throw..." << std::endl;
    }
    catch (const char* ex) // това, което е обявено като тип в catch блока трябва да съвпада по тип
    {
        std::cerr << "Exception caught: " << ex << std::endl;
    }

    std::cout << "Point 4: After the try block, after the throw..." << std::endl;

    return 0;
}