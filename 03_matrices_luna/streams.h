#ifndef _STREAMS_H
#define _STREAMS_H
#include <iostream>

using namespace std;

struct Date {
  char *day;
  char *month;
  char *year;
};

Date parseDate(char *input_date);
char *findYear(char *s);
char *createPath(char *stemplate, char *sp_year);
char *dateForCompare(char *s, Date d);
void findDatesAndCalculate(ifstream &in, char *compareString);
void calcAndPrintTime(double t);
ostream &operator<<(ostream &out, const Date &d);

#endif // !_STREAMS_H
