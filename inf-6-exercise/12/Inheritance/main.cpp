#include "Circle.h"

#include <fstream>
#include <iostream>

#include "ColouredCircle.h"
//#include "ColouredCircleWithEnum.h"

void testColouredCircle()
{
    ColouredCircle redCircle{ {1, 1}, 2, "white" };
    std::cout << "----------------------------" << std::endl;
    redCircle.setRadius(5);
    redCircle.setColour("red");
    redCircle.print();
    std::cout << "----------------------------" << std::endl;

    // ��� print � ��� ���������� �� �� ��������?
    // TODO: ��������� ��������� ���
    Circle* blueCircle = new ColouredCircle{ {1, 1}, 2, "blue" };
    blueCircle->print();

    delete blueCircle;
}

//void testColouredCircleWithEnum()
//{
//    ColouredCircle redCircle{ {1, 1}, 2, ColouredCircle::Colour::WHITE };
//    std::cout << "----------------------------" << std::endl;
//    redCircle.setRadius(5);
//    redCircle.setColour(ColouredCircle::Colour::RED);
//    redCircle.print();
//    std::cout << "----------------------------" << std::endl;
//}

int main()
{
    //testColouredCircle();
    //testColouredCircleWithEnum();

    Circle c{{0, 0}, 1 };
    ColouredCircle redCircle{ {1, 1}, 2, "white" };

    Circle* pC = &redCircle;
    pC->print();

    // ��������! ������������� �� ����� ��� ���������� ����
    //ColouredCircle* pCC = static_cast<ColouredCircle*>(&c);
    //// ����� �� ������ � �����?
    //pCC->print();
}
