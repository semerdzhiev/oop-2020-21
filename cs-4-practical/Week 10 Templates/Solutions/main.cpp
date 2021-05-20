#include <iostream>

#include "list.h"
#include "order.h"
#include "point.h"

using std::cout;
using std::endl;

int main() {
    List<Point> list;
    Order<Point> orderedList;
    Point p1(3,4);
    Point p2(1,6);
    Point p3(2,1);
    Point p5(2,1);
    Point p6(2,4);
    Point p4(2,1);
    Point p7(2,2);

    list.add(p1);
    list.add(p2);
    list.add(p3);
    list.add(p4);
    list.add(p5);
    list.add(p6);
    list.add(p7);

    for (int i = 0, size = list.size(); i < size; ++i)
    {
        cout << list[i] << endl;
    }

    cout << "---------------\n";

    orderedList.add(p1);
    orderedList.add(p2);
    orderedList.add(p3);
    orderedList.add(p4);
    orderedList.add(p5);
    orderedList.add(p6);
    orderedList.add(p7);

    orderedList.save("items.txt");
    Order<Point> newOrderedList;
    newOrderedList.read("items.txt");

    for (int i = 0, size = newOrderedList.size(); i < size; ++i)
    {
        cout << newOrderedList[i] << endl;
    }


    return 0;
}
