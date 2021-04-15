#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Time
{
private:
    unsigned seconds{};
    unsigned minutes{};
    unsigned hours{};
    Time addTime(const Time &other) const
    {
        Time newTime{};
        unsigned timeInSeconds = hours * 3600 + minutes * 60 + seconds;
        unsigned otherTimeInSeconds = other.hours * 3600 + other.minutes * 60 + other.seconds;
        unsigned newTimeInSeconds = timeInSeconds + otherTimeInSeconds;
        newTime.hours = (newTimeInSeconds / 3600) % 24;
        newTime.minutes = ((newTimeInSeconds % 3600) / 60) / 60;
        newTime.seconds = (newTimeInSeconds % 3600) % 60;
        return newTime;
    }

public:
    Time() = default;
    Time(unsigned _seconds, unsigned _minutes = 0, unsigned _hours = 0)
    {
        assert(_seconds < 60 && _minutes < 60 && _hours < 24);
        seconds = _seconds;
        minutes = _minutes;
        hours = _hours;
    }
    Time operator+(const Time &other) const
    {
        return this->addTime(other);
    }
    Time &operator+=(const Time &other)
    {
        *this = this->addTime(other);
        return *this;
    }
    bool operator<(const Time &other)
    {
        if (hours < other.hours)
        {
            return true;
        }
        if (minutes < other.minutes)
        {
            return true;
        }
        if (seconds < other.seconds)
        {
            return true;
        }
        return false;
    }
    friend std::ostream &operator<<(std::ostream &os, const Time &time);
    friend std::istream &operator>>(std::istream &is, Time &time);
};

std::ostream &operator<<(std::ostream &os, const Time &time)
{
    os << time.hours << ":" << time.minutes << ":" << time.seconds;
    return os;
}

std::istream &operator>>(std::istream &is, Time &time)
{
    unsigned hours, minutes, seconds;
    is >> seconds >> minutes >> hours;
    time = Time(seconds, minutes, hours);
    return is;
}

class TimeCollection
{
private:
    Time times[1000];
    unsigned count{0};

public:
    TimeCollection() = default;
    Time &operator[](unsigned index)
    {
        if (index >= count)
        {
            throw std::out_of_range("Index too large");
        }
        return times[index];
    }
    const Time &operator[](unsigned index) const
    {
        if (index >= count)
        {
            throw std::out_of_range("Index too large");
        }
        return times[index];
    }
    void sort()
    {
        std::sort(times, times + count);
    }
};

int main()
{
    // Time t1{40, 20, 13};
    // Time t2{15, 15, 15};

    // Time t3 = t1 + t2;
    // Time t4 = t1 += t2;

    Time t1;
    std::cin >> t1;

    std::cout << t1 << std::endl; // operator<< (std::cout, t1)

    TimeCollection t;
    t.sort();

    // cout.operator<<(6);
    // cout << 6;

    return 0;
}