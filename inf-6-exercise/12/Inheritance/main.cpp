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

    // кой print и кой деструктор ще се потърсят?
    // TODO: обяснение следващия път
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

    // внимание! преобразуване от базов към производен клас
    //ColouredCircle* pCC = static_cast<ColouredCircle*>(&c);
    //// Какво се случва с цвета?
    //pCC->print();
}
