#include <iostream>

using namespace std;

// Функция вычисления наименьшего общего делителя
int getNOD(int, int);

int main(void) {
  int a = 15;
  int b = 10;
  int c = getNOD(a, b);

  cout << "NOD(" << a << ", " << b << ") = " << c << endl;

  return 0;
}

int getNOD(int a, int b) {
  while (a != b) {
    if (a < b)
      b = b - a;
    else
      a = a - b;
  }
  return a;
}
