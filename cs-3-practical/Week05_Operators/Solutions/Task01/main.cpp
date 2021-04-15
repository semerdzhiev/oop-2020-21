#include <iostream>
#include "time.hpp"

using std::cout;

int main()
{
    Time time1(20, 15);
    Time time2(3, 50);
    Time time3;

    (time1 + time2).print();

    time3 = time1 + time2;
    time3.print();

    time3 = time1 + 5;
    time3.print();

    time3 = 6 + time1;
    time3.print();

    cout << (time1 > time2);

    return 0;
}