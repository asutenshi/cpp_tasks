#include "datetime.h"
#include <iostream>
#include <regex>

using namespace std;

DateTime::DateTime(int y, int m, int d) {
    if (y <= 0 || m < 1 || m > 12 || d < 1)
        throw DateTimeException();

    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDaysInMonth = daysInMonth[m-1];
    if (m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
        maxDaysInMonth = 29;

    if (d > maxDaysInMonth)
        throw DateTimeException();

    int a = (14 - m) / 12;
    y = y + 4800 - a;
    m = m + 12*a - 3;
    jdn = d + ((153 * m + 2) / 5) + 365*y + (y / 4) - 
    (y / 100) + (y / 400) - 32045;
}

DateTime::DateTime() {
    jdn = 0;
}

int DateTime::operator -(const DateTime &dt) const {
    return jdn - dt.jdn;
}

DateTime &DateTime::operator +=(const int &d) {
    jdn += d;
    return *this;
}

DateTime DateTime::operator +(const int &d) const {
    DateTime res(*this);
    return res += d;
}

DateTime &DateTime::operator -=(const int &d) {
    return (*this += (-d));
}

DateTime DateTime::operator -(const int &d) const {
    return (*this + (-d));
}

int DateTime::getWeekDay() {
    return jdn % 7 + 1;
}

istream& operator >>(istream& in, DateTime &dt) {
    string s;
    in >> s;
    const regex datePattern(R"([0-9]{4}\.(0[1-9]|1[012])\.(0[1-9]|[12][0-9]|3[01]))");
    if (regex_match(s, datePattern)) {
      int year = stoi(s.substr(0, 4));
      int month = stoi(s.substr(5, 2));
      int day = stoi(s.substr(8, 2));
      dt = DateTime(year, month, day);
    }
    else 
      throw DateTimeException();
    return in;
}

ostream& operator <<(ostream& out, const DateTime& dt) {
    int a = dt.jdn + 32044;
    int b = (4*a + 3) / 146097; 
    int c = a - (146097*b  / 4);
    int d = (4*c + 3) / 1461;
    int e = c - (1461*d / 4);
    int m = (5*e + 2) / 153;
    int day = (e - ((153*m + 2) / 5) + 1);
    int month = (m + 3 - 12*(m / 10));
    int year = (100*b + d - 4800 + (m / 10));
    cout << year << '.' << month << '.' << day;
    return out;
}