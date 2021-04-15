#include <iostream>
#include "time.hpp"

using std::cout;
using std::endl;

Time::Time() = default;

Time::Time(const int hour, const int minute)
{
    this->hour = (hour + minute / 60) % 24;
    this->minute = minute % 60;
}

Time &Time::operator=(Time const &other)
{
    //this is here so we don't copy ourselves
    if (this != &other)
    {
        this->hour = other.hour;
        this->minute = other.minute;
    }

    return *this;
}

Time Time::operator+(Time const &other)
{
    return Time(this->hour + other.hour, this->minute + other.minute);
}

Time Time::operator+(int const &hour)
{
    return Time(this->hour + hour, this->minute);
}

bool Time::operator>(Time const &other)
{
    return this->hour > other.hour ||
           (this->hour == other.hour && this->minute > other.minute);
}

void Time::print() const
{
    if (hour < 10)
    {
        cout << "0";
    }

    cout << hour << ":";

    if (minute < 10)
    {
        cout << "0";
    }

    cout << minute << endl;
}

Time operator+(int hour, const Time &time)
{
    Time result(time.hour + hour, time.minute);

    return result;
}