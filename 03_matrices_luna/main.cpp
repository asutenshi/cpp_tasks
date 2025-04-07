#include "streams.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
  char input_date[11]; // dd.mm.yyyy len = 10 + 1 (for \0) = 11
  do {
    cout << "Пожалуйста введите желаему дату в формате dd.mm.yyyy или пустую "
            "строку для завершения: ";
    cin.read(input_date, 11);

    Date user_date = parseDate(input_date);
    char stemplate[] = "./moon/moon****.dat\0";
    char *pathToFile = createPath(stemplate, user_date.year);
    char compareTemplate[] = "ddddmmyy\0";
    char *compareString = dateForCompare(compareTemplate, user_date);

    ifstream in(pathToFile);

    if (!in.is_open()) {
      cout << "Ошибка при открытии файла " << pathToFile << endl;
      return -1;
    }

    findDatesAndCalculate(in, compareString);
  } while (input_date[0] != '\0');

  return 0;
}
