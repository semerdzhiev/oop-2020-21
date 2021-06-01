#include "Unit.h"

#pragma once

class Zergling : public Unit {
public:
    Zergling() :  Unit(10, 30, 1, "Zergling") {

    }
};

//
//        |   pub     |  priv     | prot  < superclass
// pub    |   pub     |  priv     | prot
// priv   |   priv    |  priv     | priv
// prot   |   prot    |  priv     | prot
//
//  ^
//derived class