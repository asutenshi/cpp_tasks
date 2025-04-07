#define _USE_MATH_DEFINES

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int tFirstFx();
// int tSecondFreq();
void tThirdEllipse();
int tForthCommerce();
int tFifthMilesInKilometers();
void tSixthBinNewton();
void tSeventhFGPredel();
void tEighthSGPredel();

int main(void) {
  tFifthMilesInKilometers();
  return 0;
}

float f4(float x) { return x * x * x * x; }

float fTan(float x) { return tan(x); }

float fExp(float x) { return pow(M_E, x); }

float fSin2(float x) { return sin(x) * sin(x); }

int tFirstFx(void) {
  double a_start = -5.0;
  double a_end = 5.0;
  double a_step = 0.1;

  double eps = 1.0E-6;

  //---------------------------------------------------------------//

  bool flag = 1;
  for (double x = a_start; x <= a_end; x += a_step) {
    if (x == 0)
      continue;
    if (fabs(fTan(x) - fTan(-x)) > eps) {
      flag = 0;
      break;
    }
  }
  if (flag == 1) {
    cout << "Function is paryty" << endl;
    return 1;
  }

  //---------------------------------------------------------------//

  flag = 1;
  for (double x = a_start; x <= a_end; x += a_step) {
    if (x == 0)
      continue;
    if (fabs(fTan(x) + fTan(-x)) > eps) {
      flag = 0;
      break;
    }
  }
  if (flag == 1) {
    cout << "Function is odd" << endl;
    return 1;
  } else {
    cout << "Function is general" << endl;
    return 1;
  }

  //---------------------------------------------------------------//

  // Решение до исправлений:

  // int parity = 0, odd = 0, general = 0;

  // for (float x = -5; x <= 5; x += 0.1)
  //{
  //     if (x == 0) {
  //         continue;
  //     }

  //    float f = fTan(x);
  //    float f_minus_x = fTan(-x);

  //    if (f == f_minus_x && odd == 0)
  //    {
  //        parity++;
  //    }
  //    else if (f_minus_x == -f_minux_x && parity == 0)
  //    {
  //        odd++;
  //    }
  //    else
  //    {
  //        cout << "Function is general";
  //        return 1;
  //    }
  //}
  // if (parity > 0)
  //{
  //    cout << "Function is parity";
  //}
  // else if (odd > 0)
  //{
  //    cout << "Function is odd";
  //}
  // return 1;
}

// int tSecondFreq(void)
//{
//     float freq = M_PI;
//
//     for (float x = 0; x <= 5 * freq; x += 0.1)
//     {
//         float f = fSin2(x);
//         float f_freq = fSin2(x + freq);
//         cout << f << ' ' << f_freq;
//         if (f != f_freq)
//         {
//             cout << "quit";
//             return 0;
//         }
//     }
//     cout << "f(x) is frequently with frequency = " << freq;
//     return 1;
// }

void tThirdEllipse(void) {
  float a, b;
  cout << "Enter the a, b parametrs (a b): ";
  cin >> a >> b;

  //---------------------------------------------------------------//

  // буду проверять принадлежность x (от -a до a) и y (от b до -b) к эллипсу

  for (int y = (int)b; y >= -b; y--) {
    for (int x = -(int)a; x <= a; x++) {
      float ellipse = x * x / a / a + y * y / b / b;
      if (ellipse <= 1) {
        cout << '*';
      } else {
        cout << ' ';
      }
    }
    cout << endl;
  }
}

int tForthCommerce(void) {
  float k, p, r;
  int years = 0;

  cout << "Enter the credit value and percent per annum (value percent): ";
  cin >> k >> p;
  cout << "Enter the profit per year (value): ";
  cin >> r;

  //---------------------------------------------------------------//

  if (r > k * p / 100) {
    while (k > 0) {
      k = k + k * p / 100 - r;
      years += 1;
    }
    cout << "Yes, you will be able to pay the loan in " << years << " years";
    return 1;
  } else {
    cout << "You will not be able to repay the loan";
    return 0;
  }
}

int tFifthMilesInKilometers(void) {
  float k;
  double miles = 0;
  double kilometers = 0;

  cout << "Enter the limit to which you want to build the table (km): ";
  cin >> k;
  cout << "Miles    Kilometrs" << endl;

  //---------------------------------------------------------------//

  while (k > kilometers) {
    kilometers += 1;
    miles += 1;
    if (k > kilometers) {
      cout << fixed << setprecision(4) << left << setw(9) << kilometers * 0.6214
           << kilometers << endl;
    } else
      break;
    if (k > miles * 1.609344) {
      cout << fixed << setprecision(4) << left << setw(9) << miles
           << miles * 1.609344 << endl;
    } else
      break;

    kilometers += 1;
    if (k > kilometers) {
      cout << fixed << setprecision(4) << left << setw(9) << kilometers * 0.6214
           << kilometers << endl;
    } else
      break;
    kilometers += 1;
    if (k > kilometers) {
      cout << fixed << setprecision(4) << left << setw(9) << kilometers * 0.6214
           << kilometers << endl;
    } else
      break;
    miles += 1;
    if (k > miles * 1.609344) {
      cout << fixed << setprecision(4) << left << setw(9) << miles
           << miles * 1.609344 << endl;
    } else
      break;
  }
  return 1;
  /*float k;*/
  /*cout << "Enter the limit to which you want to build the table (km): ";*/
  /*cin >> k;*/
  /**/
  /*cout << left << setw(9) << "Miles" << "Kilometers" << endl;*/
  /**/
  /*// Инициализация переменных*/
  /*double miles = 0;*/
  /*double kilometers = 0;*/
  /**/
  /*// Шаг для миль и километров*/
  /*double mileStep = 1.609344;*/
  /*double kmStep = 1;*/
  /**/
  /*// Цикл для вывода таблицы*/
  /*while (kilometers <= k) {*/
  /*  // Вывод строки с километрами*/
  /*  cout << fixed << setprecision(4) << left << setw(9) << kilometers *
   * 0.6214*/
  /*       << kilometers << endl;*/
  /*  kilometers += kmStep;*/
  /**/
  /*  if (kilometers > k)*/
  /*    break;*/
  /**/
  /*  // Вывод строки с милями*/
  /*  cout << fixed << setprecision(4) << left << setw(9) << miles*/
  /*       << miles * mileStep << endl;*/
  /*  miles += 1;*/
  /**/
  /*  if (miles * mileStep > k)*/
  /*    break;*/
  /*}*/
  /**/
  /*return 0;*/
}

float numberComb(float m, float i) {
  if (i == 0) {
    return 1;
  } else {
    return numberComb(m, i - 1) * (m - i + 1) / i;
  }
}

void tSixthBinNewton(void) {
  float x, m;
  float bin = 0;
  cout << "Enter the x, m values for (1+x)^m (x m): ";
  cin >> x >> m;

  cout << pow(1 + x, m) << endl;

  for (int i = 0; i <= m; i++) {
    bin += numberComb(m, i) * pow(x, i);
  }
  cout << bin << endl;
}

void tSeventhFGPredel(void) {
  double e = 0.000000000001;
  // cout << "Enter the error rate (e): ";
  // cin >> e;
  double FGPredel;
  double x = 1;
  int i = 0;
  do {
    FGPredel = sin(x) / x;
    cout << "Predel " << setw(3) << setfill('0') << right << i << " : "
         << setw(10) << setfill('0') << setprecision(6) << FGPredel << " | ";
    cout << "x: " << left << setw(12) << setfill('0') << setprecision(6) << x
         << " | ";
    cout << "Equtation: " << setw(11) << setfill('0') << setprecision(6)
         << 1 - FGPredel << endl;
    x /= 2;
    i++;
  } while (fabs(1 - FGPredel) >= e);
}
void tEighthSGPredel(void) {
  double e = 0.0001;
  // cout << "Enter the error rate (e): ";
  // cin >> e;
  double SGPredel;
  double n = 1;
  do {
    SGPredel = pow(1 + 1 / n, n);
    cout << "n: " << right << setw(5) << setfill('0') << n << " | ";
    cout << "Predel : " << left << setw(10) << setfill('0') << setprecision(6)
         << SGPredel << " | ";
    cout << "Equtation: " << setw(11) << setfill('0') << setprecision(6)
         << fabs(M_E - SGPredel) << endl;
    n++;
  } while (fabs(M_E - SGPredel) >= e);
}

void tNinethInfFraction(void) {}
