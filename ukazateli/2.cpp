#include <iostream>

using namespace std;

int main(void) {
  int const N = 80;
  char str[N + 1] = {'\0'};
  char newStr[N + 1] = {'\0'};
  char *pstr = str;
  char *pnewStr = newStr;
  int strLen = 0;

  for (int i = 0; i <= N; i++) {
    *(pstr + i) = 0;
    *(pnewStr + i) = 0;
  }

  cout << "Enter the string and press enter" << endl;
  cin.getline(str, 80);

  cout << "Old string: " << endl;
  cout << str << endl;

  while (*pstr == ' ')
    pstr++;

  while (*pstr != '\0') {
    if (*pstr == ' ' && (*(pstr + 1) == ' ' || *(pstr + 1) == '\0')) {
      pstr++;
    } else {
      *pnewStr = *pstr;
      pstr++;
      pnewStr++;
      strLen++;
    }
  }

  cout << "newStr" << endl << newStr << endl;
  cout << "strLen = " << strLen << endl;

  char *pSdvig =
      pnewStr + 80 - strLen - 1; // - 1 т.к. мы закончим цикл на символе '\0'

  for (int i = 0; i <= strLen; i++) {
    *pSdvig = *pnewStr;
    *pnewStr = ' ';
    pSdvig--;
    pnewStr--;
  }

  cout << "newStrSdvig" << endl << newStr;

  return 0;
}
