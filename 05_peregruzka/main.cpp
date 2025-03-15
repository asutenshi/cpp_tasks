#include "rational.h"
#include "equations.h"
#include <iostream>

using namespace std;

int main(void) {
  // Rational r;
  // cout << "Введите дробь (numer denom): ";
  // cin >> r;
  // cout << "Вы ввели дробь: " << r << endl;
  // Rational r2;
  // cout << "Введите дробь (numer denom): ";
  // cin >> r2;
  // cout << "Вы ввели дробь: " << r2 << endl;
  // cout << "r * r2: " << r / r2 << endl;

  // Rational a(1,2), b(-1,6);
  // cout<<"a="<<a<<" b="<<b<<" a+b="<<(a+b)<<endl;
  // cout<<"a("<<a<<") *= b("<<b<<")"<<endl;
  // a *= b;
  // cout<<"a="<<a<<" b="<<b<<" a-b="<<a-b<<endl;
  // Rational c=3;
  // cout<<"b="<<b<<" c="<<c<<" b/c="<<b/c<<endl;
  // Rational e(7,8), f(5,12);
  // cout<<"e="<<e<<" f="<<f<<" e+f=?"<<endl;
  // cout<<"Введите результат g=m/n в формате: m n"<<endl;
  // Rational g;
  // cin>>g;
  // if (e+f!=g)
  //   cout<<"Неправильно! e+f="<<e+f<<endl;
  // else
  //   cout<<"Правильно!"<<endl;
  // Rational k(256, 4);
  // Rational b(8, 4);
  // cout << "y = " << k << "*x + " << b << endl;
  // cout << "корень = " << linear_eq(k, b) << endl;
  // cout << "квадратный корень из " << k << " = " << k.sqrt() << endl;

  // Rational a(12, 15);
  // Rational b(8, 3);
  // Rational c(1, 9);
  // Rational out[2] = {0, 0};
  // quad_eq(a, b, c, out);
  
  // cout << "Для уравнения y = (" << a << ")*x^2 + (" << b << ")*x + (" << c
  //   << ") x1 = " << out[0] << " x2 = " << out[1] << endl;

  double a = -3.14;
  long long* bits = (long long*)&a;
  int sign = (*bits >> 63) & 1;
  cout << sign << endl;

  return 0;
}
