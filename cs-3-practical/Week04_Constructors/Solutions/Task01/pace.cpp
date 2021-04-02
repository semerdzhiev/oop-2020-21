#include <iostream>
#include <cmath>
#include "pace.h"

using std::cout;

Pace::Pace()
{
    minutes = 0;
    seconds = 0;
}

Pace::Pace(double speed)
{
    if (speed > 0) {
        double time = MINUTES_IN_HOUR / speed;
        minutes = floor(time);
        seconds = (time - minutes) * SECONDS_IN_MINUTE;
    } else {
        minutes = 0;
        seconds = 0;
    }
}

Pace::Pace(int minutes, int seconds)
{
    if (minutes > 0 && seconds > 0) {
        this->minutes = minutes;
        this->seconds = seconds;
    }
}

double Pace::getSpeed()
{
    if ((minutes * SECONDS_IN_MINUTE + seconds) != 0) {
        return MINUTES_IN_HOUR / (minutes + seconds / SECONDS_IN_MINUTE);
    }

    return 0;
}

double Pace::getTempo()
{
    return (double) minutes + seconds / SECONDS_IN_MINUTE;
}

void Pace::printTempo()
{
    cout << minutes << "' " << seconds << '"'; 
}