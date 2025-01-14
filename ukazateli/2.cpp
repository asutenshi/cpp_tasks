#include <iomanip>
#include <iostream>

using namespace std;

int main(void) {
  int const N = 80;
  char str[N + 1];
  char newStr[N + 1];
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

  for (int i = 0; i < N && *pstr != 0; i++) {
    if ((i == 0 || i == N - 1) && *pstr == ' ') {
      while (*pstr == ' ') {
        pstr++;
        continue;
      }
    } else if (*pstr == ' ' && *(pstr + 1) == ' ') {
      pstr++;
      continue;
    } else {
      *pnewStr = *pstr;
      pstr++;
      pnewStr++;
      strLen++;
    }
  }

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

  return 0;
}
