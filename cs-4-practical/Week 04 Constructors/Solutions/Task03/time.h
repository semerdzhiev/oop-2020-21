#ifndef TIME
#define TIME

#include <cstring>
#include <stdlib.h>

enum TimeZone {
    NEW_YORK = -5,
    LONDON = 0,
    SOFIA = 2,
    MOSCOW = 3
};

class Time
{
    const static int HOURS_A_DAY = 24; 
    
    int utcHour, utcMinute;

    char *getTimeString(int hour, int minute);

public:
    Time() : utcHour(0), utcMinute(0) {};
    Time(int hours, int minutes, TimeZone zone);

    char *getNewYorkTime();
    char *getLondonTime();
    char *getSofiaTime();
    char *getMoscowTime();
};

#endif