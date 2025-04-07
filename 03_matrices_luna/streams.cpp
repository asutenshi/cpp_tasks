#include "streams.h"
#include "math.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Date parseDate(char *input_date) {
  Date d;
  d.day = input_date;
  d.month = strstr(input_date, ".") + 1;
  d.year = strstr(strstr(input_date, ".") + 1, ".") + 1;
  return d;
}

char *createPath(char *stemplate, char *sp_year) {
  char *temp = strstr(stemplate, "****");
  for (int i = 0; i < 4; i++)
    *(temp + i) = *(sp_year + i);
  return stemplate;
}

char *dateForCompare(char *s, Date d) {
  for (int i = 0; i < 4; i++)
    s[i] = *(d.year + i);
  s[4] = *d.month;
  s[5] = *(d.month + 1);
  s[6] = *d.day;
  s[7] = *(d.day + 1);
  return s;
}

void findDatesAndCalculate(ifstream &in, char *compareString) {
  double max_p_ev, max_c_ev, max_n_ev;
  double max_p_t, max_c_t, max_n_t;
  string prev_line;
  getline(in, prev_line);

  string curr_line;
  while (getline(in, curr_line)) {
    bool equals = true;
    for (int i = 0; i < 8; i++) {
      if (curr_line[i] != *(compareString + i)) {
        equals = false;
        break;
      }
    }
    if (equals) {
      double prev_ev = stod(prev_line.substr(36, 8));
      double prev_time = stod(prev_line.substr(16, 6));
      double curr_ev = stod(curr_line.substr(36, 8));
      double curr_time = stod(curr_line.substr(16, 6));
      if (prev_ev > 0 && curr_ev < 0) {
        cout << "Заход луны будет в ";
        calcAndPrintTime(linearFind(prev_time, prev_ev, curr_time, curr_ev));
        cout << endl;
        /*cout << prev_line << '\t' << prev_ev << " t = " << prev_time << endl;
        cout << curr_line << '\t' << curr_ev << " t = " << curr_time << endl;*/
      } else if (prev_ev < 0 && curr_ev > 0) {
        cout << "Восход луны будет в ";
        calcAndPrintTime(linearFind(prev_time, prev_ev, curr_time, curr_ev));
        cout << endl;
        /*cout << prev_line << '\t' << prev_ev << " t = " << prev_time << endl;
        cout << curr_line << '\t' << curr_ev << " t = " << curr_time << endl;*/
      } else if (prev_ev > 0 && curr_ev > 0 && curr_ev > prev_ev &&
                 curr_ev >= max_c_ev) {
        string next_line;
        getline(in, next_line);
        double next_ev = stod(next_line.substr(36, 8));
        double next_time = stod(next_line.substr(16, 6));
        max_p_ev = prev_ev;
        max_p_t = prev_time;
        max_c_ev = curr_ev;
        max_c_t = curr_time;
        max_n_ev = next_ev;
        max_n_t = next_time;
        curr_line = next_line;
      }
    }
    prev_line = curr_line;
  }
  cout << "Кульминация луны будет в ";
  calcAndPrintTime(
      quadFind(max_p_t, max_p_ev, max_c_t, max_c_ev, max_n_t, max_n_ev));
  cout << endl;
}

void calcAndPrintTime(double t) {
  double hours, minutes, seconds;
  hours = (int)(t);
  minutes = (t - hours) * 60;
  seconds = (minutes - (int)(minutes)) * 60;
  if (hours < 0) {
    cout << "error";
  } else {
    cout << hours << " часов, " << (int)(minutes + 0.5) << " минут, "
         << (int)(seconds + 0.5) << " секунд.";
  }
}

ostream &operator<<(ostream &out, const Date &d) {
  out << "Date = " << d.day << " day, " << d.month << " month, " << d.year
      << " year";
  return out;
}
