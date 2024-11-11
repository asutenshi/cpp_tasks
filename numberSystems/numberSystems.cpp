#include <iostream>

using namespace std;

int main(void) {
  cout << "From p number system to 10 number system" << endl;

  int p;
  do {
    cout << "Enter number system p base (2...36): ";
    cin >> p;
  } while (p < 2 || p > 36);

  const int MAX_LEN = 30;

  cout << "Enter number (number length < 30): ";
  char x[MAX_LEN + 1];
  cin.getline(x, 1, '\n');
  cin.getline(x, MAX_LEN + 1, '\n');

  int n = 0;

  for (int i = 0; x[i] != 0; i++) {
    n *= p;
    int d = -1;

    if (x[i] >= '0' && x[i] <= '9')
      d = x[i] - '0';

    if (x[i] >= 'a' && x[i] <= 'z')
      d = 10 + x[i] - 'a';

    if (x[i] >= 'A' && x[i] <= 'Z')
      d = 10 + x[i] - 'A';

    if (d < 0 || d >= p) {
      cout << "Number " << x[i] << " is incorrect" << endl;
      return -1;
    }

    n += d;
  }

  cout << "Number in 10 number system: " << n << endl;

  return 0;
}
