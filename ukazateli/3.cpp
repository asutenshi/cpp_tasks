#include <iostream>

using namespace std;

int main(void) {
  int const N = 80;
  char str[N + 1];
  char *pstr = str;
  int numbers[10];
  int *pnumbers = numbers;

  for (int i = 0; i <= N; i++)
    *(pstr + i) = 0;

  for (int i = 0; i < 10; i++) {
    *(pnumbers + i) = i;
    cout << "pnumbers = " << *pnumbers << " pnumbers + i = " << *(pnumbers + i)
         << endl;
  }

  cout << "Enter the string and press enter" << endl;
  cin.getline(str, 80);

  for (int i = 0; i < N; i++) {
    if (*(pstr + i) >= '0' && *(pstr + i) <= '9') {
      *(pnumbers + *(pstr + i) - '0') += 1;
    }
  }

  for (int i = 0; i < 10; i++) {
    cout << "pnumbers = " << *pnumbers << " pnumbers + i = " << *(pnumbers + i)
         << endl;
  }

  int max = 0;
  int max_i = 0;
  for (int i = 0; i < 10; i++) {
    if (max <= *(pnumbers + i)) {
      max = *(pnumbers + i);
      max_i = i;
    }
  }

  cout << "Most frequently repeated number = " << max_i << endl;
}
