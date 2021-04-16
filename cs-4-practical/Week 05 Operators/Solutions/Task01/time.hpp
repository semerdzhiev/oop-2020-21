#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int hour;
    int minute;

public:
    Time();
    Time(int const, int const);

    Time &operator=(Time const &other);
    Time operator+(Time const &other);
    Time operator+(int const &minute);
    bool operator>(Time const &other);

    void print() const;

    friend Time operator+(int hour, const Time &t);
};

#endif