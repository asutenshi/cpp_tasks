#ifndef _DATETIME_H
#define _DATETIME_H

#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class DateTimeException {};

class DateTime {
    int jdn;

    public:
    DateTime(int y, int m, int d);
    DateTime();
    int operator -(const DateTime &dt) const;
    DateTime &operator -=(const int &d);
    DateTime operator -(const int &d) const;
    DateTime &operator +=(const int &d);
    DateTime operator +(const int &d) const;
    int getWeekDay();
    friend ostream& operator <<(ostream& out, const DateTime& dt);
    friend istream& operator >>(istream& in, DateTime& dt);
};

#endif