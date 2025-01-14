#include <iostream>

using namespace std;

int main(void) {
  int const N = 80;
  char str[N + 1] = {'\0'};
  char *pstr = str;
  int numbers[10] = {0};
  int *pnumbers = numbers;

  cout << "Enter the string and press enter" << endl;
  cin.getline(str, 80);

  while (*pstr != '\0') {
    if (*pstr >= '0' && *pstr <= '9') {
      numbers[*pstr - '0']++;
    }
    pstr++;
  }

  int max = 0;
  int max_i = 0;
  for (int i = 0; i < 10; i++) {
    if (max <= *pnumbers) {
      max = *pnumbers;
      max_i = i;
    }
    pnumbers++;
  }

  if (max_i == 9 && max == 0) {
    cout << "String hasn't numbers" << endl;
  } else
    cout << "Most frequently repeated number = " << max_i << endl;
  return 0;
}
