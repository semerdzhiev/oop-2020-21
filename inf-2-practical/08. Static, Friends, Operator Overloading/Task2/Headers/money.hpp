#pragma once;

#include <iostream>

using namespace std;

class Money
{
private:
    unsigned banknotes, coins;

    unsigned asCoins() const;
    void normalize();
    void addMoney(const Money& other);
    void removeMoney(const Money& other);

public:
    Money(unsigned _coins = 0, unsigned _banknotes = 0);
    
    Money operator+(const Money& other) const;
    Money& operator+=(const Money& other);
    Money operator-(const Money& other);
    Money& operator-=(const Money& other);
   
    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator>=(const Money& other) const;
    bool operator<=(const Money& other) const;
    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;

    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream& operator>>(istream& is, Money& money);
};
