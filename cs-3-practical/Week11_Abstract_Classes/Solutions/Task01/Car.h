#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
    double maxSpeed;
    double currentSpeed;
    double price;

protected:
    void copy(double maxSpeed, double currentSpeed, double price);

public:
    Car();
    Car(double maxSpeed, double currentSpeed, double price);
    Car(Car const &other);
    Car &operator=(Car const &other);
    ~Car();

    virtual void startEngine();
    virtual void stopEngine();
    virtual void accelerate() = 0;

    double getMaxSpeed() const { return this->maxSpeed; }
    double getCurrentSpeed() const { return this->currentSpeed; }
    void setCurrentSpeed(double currentSpeed) { this->currentSpeed = currentSpeed; }
    double getPrice() const { return this->price; }
};

#endif /* ifndef CAR_H */