#include <iostream>

using namespace std;

int main(void) {
  float grad, minute, second;
  int a;

  grad = -125.0;
  minute = 30.0;
  second = 10.0;

  cout << "float = " << sizeof(float) * 8 << " bit\n";
  cout << "operation = " << (*(int *)&grad) << endl;
  cout << "grad(dec) = " << grad << endl;
  a = (*(int *)&grad) & INT_MAX;
  cout << "|grad| = " << *(float *)&a << endl;
  cout << "a(dec) = " << dec << a << " a(hex) = " << hex << a << endl;
  cout << "adress grad = " << &grad << endl << endl;

  a = *(int *)&grad;
  cout << "a(dec) = " << a << " a(hex) = " << hex << a << endl;
  int sign = a >> 31;
  cout << "sign = " << dec << sign << endl;
}
