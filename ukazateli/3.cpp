#include <iostream>

using namespace std;

int main(void) {
  int const N = 80;
  char str[N + 1];
  char *pstr = str;
  int numbers[10];
  int *pnumbers = numbers;

  for (int i = 0; i < 10; i++) {
    *pnumbers = 0;
    pnumbers++;
  }
  pnumbers = numbers;

  cout << "Enter the string and press enter" << endl;
  cin.getline(str, 80);

  for (int i = 0; i < N; i++) {
    if (*pstr >= '0' && *pstr <= '9') {
      numbers[*(pstr+i) - '0']++;
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

  cout << "Most frequently repeated number = " << max_i << endl;
} 
