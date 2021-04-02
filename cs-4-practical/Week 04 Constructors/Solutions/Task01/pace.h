#ifndef PACE
#define PACE

class Pace
{
    const static int SECONDS_IN_MINUTE = 60;
    const static int MINUTES_IN_HOUR = 60;

    int minutes;
    double seconds;

public:
    Pace();
    Pace(double speed);
    Pace(int minutes, int seconds);
    double getSpeed();
    double getTempo();
    void printTempo();
};

#endif