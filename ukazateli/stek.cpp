#include <iostream>

using namespace std;

int main(void) {
  int const SIZE_STR = 80;
  char str[SIZE_STR + 1] = {'\0'};
  char *pstr = str;

  int const SIZE_STEK = SIZE_STR / 2;
  char stek[SIZE_STEK] = {'\0'};
  char *pstek = stek;

  cin.getline(str, SIZE_STR);

  return 0;
}
