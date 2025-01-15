#include <iostream>

using namespace std;

int brackets(const char c);

int main(void) {
  int const SIZE_STR = 80;
  char str[SIZE_STR + 1] = {'\0'};
  char *pstr = str;

  int const SIZE_STEK = SIZE_STR / 2;
  char stek[SIZE_STEK] = {'\0'};
  char *pstek = stek;

  cin.getline(str, SIZE_STR);

  while (*pstr != '\0') {
    int bracket = brackets(*pstr);
    if (bracket > 0) {
      *pstek = *pstr;
      pstek++;
    } else if (bracket < 0) {
      if (brackets(*pstek) == -bracket) {
        *pstek = '\0';
        if (pstek != stek) {
          pstek--;
        }
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
