#include <iostream>

#include <cassert>
#include <vector>

// �� ����� �������� ������ ����������� �������� ������ ��� ���������?
int findFirstElement(const int* array, size_t size, int elem)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        if (array[i] == elem)
            return i;
    }

    // � ������, �� ��������� �� � ������
    return -1;
}

// �� �� ��������� ������� �� y == 0
double divide(int x, int y)
{
    return static_cast<double>(x) / y;
}

// �� �� ������� ��������� �� ���������, ����� �� �� �������� ���������� �� result
bool divide(int x, int y, double& result)
{
    if (0 == y)
        return false;

    result = static_cast<double>(x) / y;
    return true;
}

// ������ ������� �� ���������� �� ����������
int main()
{
    std::cout << "Point 1: Before the try block..." << std::endl;
    try
    {
        std::cout << "Point 2: Inside the try block, before the throw..." << std::endl;

        throw "Error"; // ������������ � �� ��� �������� ���

        std::cout << "Point 3: Inside the try block, after the throw..." << std::endl;
    }
    catch (const char* ex) // ����, ����� � ������� ���� ��� � catch ����� ������ �� ������� �� ���
    {
        std::cerr << "Exception caught: " << ex << std::endl;
    }

    std::cout << "Point 4: After the try block, after the throw..." << std::endl;

    return 0;
}