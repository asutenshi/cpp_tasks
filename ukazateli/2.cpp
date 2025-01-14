<<<<<<< HEAD
#include <iomanip>
=======
>>>>>>> bebf488d22da3da9255ed5009774980736f401da
#include <iostream>

using namespace std;

int main(void) {
  int const N = 80;
<<<<<<< HEAD
  char str[N + 1];
  char newStr[N + 1];
=======
  char str[N + 1] = {'\0'};
  char newStr[N + 1] = {'\0'};
>>>>>>> bebf488d22da3da9255ed5009774980736f401da
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

<<<<<<< HEAD
  for (int i = 0; i < N && *pstr != 0; i++) {
    if ((i == 0 || i == N - 1) && *pstr == ' ') {
      while (*pstr == ' ') {
        pstr++;
        continue;
      }
    } else if (*pstr == ' ' && *(pstr + 1) == ' ') {
      pstr++;
      continue;
=======
  while (*pstr == ' ')
    pstr++;

  while (*pstr != '\0') {
    if (*pstr == ' ' && (*(pstr + 1) == ' ' || *(pstr + 1) == '\0')) {
      pstr++;
>>>>>>> bebf488d22da3da9255ed5009774980736f401da
    } else {
      *pnewStr = *pstr;
      pstr++;
      pnewStr++;
      strLen++;
    }
  }

<<<<<<< HEAD
  pnewStr = newStr;
  char *psdvigStr = newStr;
  pnewStr += strLen;
  psdvigStr += N;
  for (int i = 0; i <= strLen; i++) {
    *psdvigStr = *pnewStr;
    *pnewStr = ' ';
    psdvigStr--;
    pnewStr--;
  }

  cout << "New string: " << endl;
  cout << setw(80) << setfill('0') << left << newStr << endl;
  cout << "strLen = " << strLen << endl;
=======
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
>>>>>>> bebf488d22da3da9255ed5009774980736f401da

  return 0;
}
