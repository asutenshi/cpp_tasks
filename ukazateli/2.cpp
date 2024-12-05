#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
  int const N = 80;
  char str[N + 1] = {'0'};
  char newStr[N + 1];
  char *pstr = str;
  char *pnewStr = newStr;
  int strLen = 0;

  cout << "Enter the string and press enter" << endl;
  cin.getline(str, 80);

  cout << "Old string: " << endl;
  cout << str << endl;

  for (int i = 0; i < N; i++) {
    if (*pstr != 0) {
        strLen++;
    }
    if ((i == 0 || i == N-1) && *pstr == ' ') {
        while (*pstr == ' ') {
            pstr++;
            continue;
        }
    }
    else if (*pstr == ' ' && *(pstr+1) == ' ') {
        pstr++;
        continue;
    }
    else {
        *pnewStr = *pstr;
        pstr++;
        pnewStr++;
    }
  }
  pnewStr = newStr;
  char *pSdvig = pnewStr + 80 - strLen;
  cout << "pSdvig ind = " << 80 - strLen << endl;

  for (int i = 0; i < N; i++) {
      if (*pnewStr == '0'){ 
          break;
      }
      *pSdvig = *pnewStr;
      *pnewStr = 0;
      pnewStr++;
      pSdvig++;
  }

  newStr[N] = 0;

  cout << "New string: "<< endl;
  cout << newStr << endl;
  cout << "StrLen = " << strLen << endl;

  return 0;
}
