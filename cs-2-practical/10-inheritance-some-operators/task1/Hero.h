//
// Created by petko on 26/04/2021.
//

#pragma once
#include"Entity.h"
#include "Vilian.h"


class Hero : public Entity{
    Vilian worstEnemy;
    std::string motto;
public:
    Hero(std::string  name, std::vector<Power>  powers,
         unsigned short heath,Vilian worstEnemy, std::string motto);

    void addPower(const Power &power) override;
};


