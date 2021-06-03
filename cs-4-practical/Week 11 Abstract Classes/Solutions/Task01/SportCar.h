#ifndef SPORT_CAR_H
#define SPORT_CAR_H

#include "Car.h"

class SportCar : public Car
{

public:
    SportCar();
    SportCar(double maxSpeed, double currentSpeed, double price);
    SportCar(SportCar const &other);
    SportCar &operator=(SportCar const &other);
    ~SportCar();

    void startMovement();
    void stopMovement();
    void accelerate();
};

#endif /* ifndef SPORT_CAR_H */