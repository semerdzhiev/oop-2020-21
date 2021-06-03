#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << add(5, 3) << '\n';

    return 0;
}


//int (*pFcn)(int, int) = add;
