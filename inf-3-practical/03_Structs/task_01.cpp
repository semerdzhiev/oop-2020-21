#include <iostream>
#include <cstring>

const int MAX_SIZE = 128;
const int MAX_EVENTS_SIZE = 50;

struct Date 
{
    unsigned day;
    unsigned month;
    unsigned year;
};

bool isLeapYear(unsigned year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool isValidDate(unsigned day, unsigned month, unsigned year)
{
    unsigned months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (!year || !month || !day || month > 12)
		return 0;
	if (isLeapYear(year) && month == 2)
		months[1]++;
	if (day > months[month - 1])
		return 0;
	return 1;
}

Date createDate(unsigned day, unsigned month, unsigned year)
{
    if(!isValidDate(day, month, year))
        return Date();
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

void printDate(const Date& date)
{
    std::cout << date.day << '.' << date.month << '.' << date.year << std::endl;
}

void updateDateDay(Date& date, unsigned day)
{
    if(isValidDate(day, date.month, date.year))
        date.day = day;
}

void updateDateMonth(Date& date, unsigned month)
{
    if(isValidDate(date.day, month, date.year))
        date.month = month;
}

void updateDateYear(Date& date, unsigned year)
{
    if(isValidDate(date.day, date.month, year))
        date.year = year;
}

struct Event
{
    Date date;
    int duration;
    char description[MAX_SIZE];
};

Event createEvent(const Date& date, int duration, const char* description)
{
    Event event;
    strcpy(event.description, description);
    event.date = date;
    event.duration = duration;
    return event;
}

void printEvent(const Event& event)
{
    printDate(event.date);
    std::cout << event.duration << std::endl;
    std::cout << event.description << std::endl;
}

struct Calendar
{
    Event events[MAX_EVENTS_SIZE];
    int current;
};

Calendar createCalendar()
{
    Calendar calendar;
    calendar.current = 0;
    return calendar;
}

// -1 -> first > second
//  0 -> first == second
//  1 -> first < second
int compareDates(const Date& first, const Date& second)
{
    if(first.year > second.year)
    {
        return 1;
    }
    else if(first.year == second.year)
    {
        if(first.month > second.month)
        {
            return 1;
        }
        else if(first.month == second.month)
        {
            if(first.day > second.day)
            {
                return 1;
            }
            else if(first.day == second.day)
            {
                return 0;
            }
        }
    }
    return -1;
}

int durationForDay(const Calendar& cal, const Date& date)
{
    int durationSum = 0;
    for(size_t i = 0; i < cal.current; i++)
    {
        if(!compareDates(cal.events[i].date, date))
        {
            durationSum += cal.events[i].duration;
        }
    }
    return durationSum;
}

bool addEvent(Calendar& calendar, const Event& event)
{
    if(durationForDay(calendar, event.date) > 6)
        return false;
    
    if(calendar.current >= MAX_EVENTS_SIZE)
        return false;

    calendar.events[calendar.current] = event;
    calendar.current++;
    
    return true;
}

bool editEvent(Calendar& calendar, const char* description, const Date& newDate, int newDuration)
{
    for(size_t i = 0; i < calendar.current; i++)
    {
        if(!strcmp(calendar.events[i].description, description))
        {
            calendar.events[i].date = newDate;
            calendar.events[i].duration = newDuration;
            return true;
        }
    }
    return false;
}

void sortByDate(Calendar& calendar)
{
    for (size_t i = 0; i < calendar.current - 1; i++)
    {
        int min = i;
        for (size_t j = i+1; j < calendar.current; j++)
        {
            if (compareDates(calendar.events[j].date, calendar.events[min].date) == 1)
            {
                min = j;
            }
        }

        if (min != i) 
        {
            Event temp = calendar.events[i];
            calendar.events[i] = calendar.events[min];
            calendar.events[min] = temp;
        }
    }
}

void printEvents(const Calendar& calendar, const Date& date)
{
    for(size_t i = 0; i < calendar.current; i++)
    {
        if(!compareDates(calendar.events[i].date, date))
        {
            printEvent(calendar.events[i]);
        }
    }
}

int main() 
{

    return 0;
}