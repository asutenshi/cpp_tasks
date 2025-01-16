#include <iostream>

using namespace std;

int brackets(const char c);

int main(void) {
  int const SIZE_STR = 80;
  char str[SIZE_STR + 1] = {'\0'};
  char *pstr = str;

  int const SIZE_STEK =
      SIZE_STR / 2; // корректная расстоновка скобок возможна только в случае
                    // если в строке size / 2 октрывающих скобок
  char stek[SIZE_STEK] = {'\0'};
  char *pstek = stek;

  cin.getline(str, SIZE_STR);

  while (*pstr != '\0') { // в условие учитывается выход за пределы стека
    int bracket =
        brackets(*pstr); // функция используется для того, чтобы программа
                         // работала одинаково при любой кодировке
    if (bracket > 0 &&
        pstek <= stek + SIZE_STEK) { // если открывающая скобка кидаем в стек
      cout << bracket << " > 0 " << *pstr << endl;
      *pstek = *pstr;
      pstek++;
    } else if (bracket < 0 && pstek >= stek) { // если закрывающая скобка, то
                                               // проверяем сотсветсвует ли
      // скобка на верхну стека скобке закрывающей
      cout << bracket << " < 0 " << *pstr << endl;
      pstek--;
      if (brackets(*pstek) == -bracket) {
        *pstek = '\0';
      } else {
        cout << "Incorrect brackets combination" << endl;
        return -1;
      }
    }
    pstr++;
  }

  if (*pstek == '\0' && pstek == stek) {
    cout << "Correct" << endl;
    return 1;
  } else {
    cout << "Incorrect brackets combination" << endl;
    return -1;
  }

  return 0;
}

int brackets(const char c) {
  switch (c) {
  case '(':
    return 1;
  case ')':
    return -1;
  case '[':
    return 2;
  case ']':
    return -2;
  case '{':
    return 3;
  case '}':
    return -3;
  default:
    return 0;
  }
}
