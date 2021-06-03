#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{

public:
    virtual void startMovement() = 0;
    virtual void stopMovement() = 0;
};

#endif /* ifndef VEHICLE_H */