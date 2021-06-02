#include "Circle.h"

#include <fstream>
#include <iostream>

#include "Figure.h"
#include "ColouredCircle.h"
#include "Scatch.h"

#include <stdexcept>

void testColouredCircle()
{
    Circle* blueCircle = new ColouredCircle{ {1, 1}, 2, "blue" };

    std::cout << "----------------------------" << std::endl;
    // функцията е виртуална, указателят сочи към обект от ColouredCircle
    // ще бъде извикана функцията от класа ColouredCircle
    blueCircle->print();

    // деструкторът в базовия клас е виртуален, 
    // тъй като указателят сочи към обект от ColouredCircle,
    // ще бъде извикан деструкторът на класа ColouredCircle
    delete blueCircle;
    std::cout << "----------------------------" << std::endl;
}

size_t countBlueCircles(const Scatch& scatch)
{
    size_t count = 0;

    size_t size = scatch.size();
    for (size_t i = 0; i < size; ++i)
    {
        const Figure* currentFigure = scatch.at(i);

        const ColouredCircle* pCC = dynamic_cast<const ColouredCircle*>(currentFigure);
        if (pCC)
        {
            if (strcmp(pCC->getColour(), "blue") == 0)
            {
                ++count;
            }
        }
    }

    return count;
}

int main()
{
    Circle circle{ {0,0}, 1 };
    ColouredCircle blueCircle{ {1, 1}, 2, "blue" };

    Circle& rC = circle;
    try
    {
        ColouredCircle& rCC = dynamic_cast<ColouredCircle&>(rC);
    }
    catch (const std::bad_cast& ex)
    {
        std::cout << "The object was not of type ColouredCircle!" << std::endl;
    }

    Scatch scatch;
    scatch.addFigure(&circle);
    scatch.addFigure(&blueCircle);

    scatch.print();

    std::cout << "Count blue circles: " << countBlueCircles(scatch) << std::endl;
}
