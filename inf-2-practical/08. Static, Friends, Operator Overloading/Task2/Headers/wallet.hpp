#pragma once

#include "money.hpp"

class Wallet
{
    Money money{};

public:

    void addMoney(const Money& _money);
    void removeMoney(const Money& _money);
   
    friend ostream& operator<<(ostream& os, const Wallet& wallet);
    friend istream& operator>>(istream& is, Wallet& wallet);
};  