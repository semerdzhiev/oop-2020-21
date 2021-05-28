#ifndef FAMILY_CAR_H
#define FAMILY_CAR_H

#include "Car.h"

class FamilyCar : public Car
{

public:
    FamilyCar();
    FamilyCar(double maxSpeed, double currentSpeed, double price);
    FamilyCar(FamilyCar const &other);
    FamilyCar &operator=(FamilyCar const &other);
    ~FamilyCar();

    void startMovement();
    void stopMovement();
    void accelerate();
};

#endif /* ifndef FAMILY_CAR_H */