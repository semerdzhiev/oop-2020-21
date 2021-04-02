#include "time.h"

char *Time::getTimeString(int hour, int minute)
{
    static char result[32] = "";
    memset(result, 0, sizeof result);
    char buffer[32];

    itoa(hour, buffer, 10);
    strcat(result, buffer);
    strcat(result, ":");

    itoa(minute, buffer, 10);
    strcat(result, buffer);

    return result;
}

Time::Time(int hours, int minutes, TimeZone zone)
{
    utcHour = hours - zone;
    utcMinute = minutes;
}

char *Time::getNewYorkTime()
{
    int hour = (utcHour + NEW_YORK) % HOURS_A_DAY;
    return getTimeString(hour, utcMinute);
}

char *Time::getLondonTime()
{
    int hour = (utcHour + LONDON) % HOURS_A_DAY;
    return getTimeString(hour, utcMinute);
}

char *Time::getSofiaTime()
{
    int hour = (utcHour + SOFIA) % HOURS_A_DAY;
    return getTimeString(hour, utcMinute);
}

char *Time::getMoscowTime()
{
    int hour = (utcHour + MOSCOW) % HOURS_A_DAY;
    return getTimeString(hour, utcMinute);
}
