#include <iostream>

using namespace std;

int main(void) {
  int const N = 80;
  char str[N + 1] = {'\0'};
  char *pstr = str;
  int numbers[10] = {0};
  int *pnumbers = numbers;

<<<<<<< HEAD
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
=======
  cout << "Enter the string and press enter" << endl;
  cin.getline(str, 80);

  while (*pstr != '\0') {
    if (*pstr >= '0' && *pstr <= '9') {
      numbers[*pstr - '0']++;
>>>>>>> bebf488d22da3da9255ed5009774980736f401da
    }
  }

  for (int i = 0; i < 10; i++) {
    cout << "pnumbers = " << *pnumbers << " pnumbers + i = " << *(pnumbers + i)
         << endl;
  }

  int max = 0;
  int max_i = 0;
  for (int i = 0; i < 10; i++) {
<<<<<<< HEAD
    if (max <= *(pnumbers + i)) {
      max = *(pnumbers + i);
      max_i = i;
    }
  }

  cout << "Most frequently repeated number = " << max_i << endl;
=======
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
>>>>>>> bebf488d22da3da9255ed5009774980736f401da
}
