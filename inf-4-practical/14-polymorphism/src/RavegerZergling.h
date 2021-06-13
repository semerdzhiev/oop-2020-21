#pragma once

#include "Zergling.h"
#include "Raveger.h"
//
//        |  Unit(rav)   |
//
//        Unit
//      <       >
//  Raveger     Zergling
//      >       <
//     RavegerZergling


class RavegerZergling : public virtual Raveger, public virtual Zergling {
public:
    RavegerZergling()
    {
//        Zergling::attack = 7;
//        Raveger::attack = 5;
//        std::cout << attack;
    }
};

class ravExp : public Raveger
{

};

class SomethingElse {
private:
    Raveger rav;
};

//RavegerZergling
//{
//    Raveger->Unit->attack;
//    Zergling->Unit->attack
//};
