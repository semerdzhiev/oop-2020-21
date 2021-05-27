#include <iostream>
#include <string.h>

#include "SportCar.h"
#include "FamilyCar.h"

int main()
{
    SportCar sportCar = SportCar(250, 0, 150000);

    sportCar.startEngine();
    sportCar.startMovement();

    std::cout << sportCar.getCurrentSpeed() << std::endl;

    sportCar.accelerate();

    std::cout << sportCar.getCurrentSpeed() << std::endl;

    sportCar.stopMovement();

    std::cout << sportCar.getCurrentSpeed() << std::endl;

    sportCar.stopEngine();

    // Family car
    FamilyCar familyCar = FamilyCar(200, 0, 45000);

    familyCar.startEngine();
    familyCar.startMovement();

    std::cout << familyCar.getCurrentSpeed() << std::endl;

    familyCar.accelerate();

    std::cout << familyCar.getCurrentSpeed() << std::endl;

    familyCar.stopMovement();

    std::cout << familyCar.getCurrentSpeed() << std::endl;

    familyCar.stopEngine();
}