#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{
    int h = hours + other.hours;
    int m = minutes + other.minutes;

    h = h + (m / 60);
    m = m % 60;

    return Time(h, m);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{
    minutes += other.minutes;
    hours += other.hours + (minutes / 60);
    minutes %= 60;
    return *this; 
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    return (hours * 60 + minutes) < (other.hours * 60 + other.minutes);
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    return (hours * 60 + minutes) > (other.hours * 60 + other.minutes);
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return (hours == other.hours) && (minutes == other.minutes);
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.hours << " hours, " << tm.minutes << " minutes";
    return os;
}
