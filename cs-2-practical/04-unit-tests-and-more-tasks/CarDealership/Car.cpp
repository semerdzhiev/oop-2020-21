#include "Car.h"
#include <iostream>

Car::Car(const EngineDetails &ed, const VisualDetails &vd, const ManufactureDetails &md, bool _isNew,
         unsigned int _price):
         engineDetails(ed),visualDetails(vd),manufactureDetails(md),isNew(_isNew),price(_price){}