#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int tForthCommerce();
int tFifthMilesInKilometers();
void tFirstFx();

int main(void)
{
    tFirstFx();
    return 0;
}
float f4(float x)
{
   return x * x * x * x;
}
float fTan(float x)
{
    return tan(x);
}

void tFirstFx(void)
{
    int parity = 0, odd = 0, general = 0;

    for (float x = -5; x <= 5; x += 0.1)
    {
        if (x == 0) {
            continue;
        }

        float f = fTan(x);
        float f_minus_x = fTan(-x);
        cout << f << ' ' << f_minus_x << ' ' << f << endl;

        if (f == f_minus_x)
        {
            parity++;
        }
        else if (f == -f)
        {
            odd++;
        }
        else
        {
            cout << "Function is general";
            break;
        }
    }
    if (parity > 0 && odd == 0 && general == 0)
    {
        cout << "Function is parity";
    }
    else if (odd > 0 && parity == 0 && general == 0)
    {
        cout << "Funcrion is odd";
    }
}

int tForthCommerce(void)
{
    float k, p, r;
    int years = 0;

    cout << "Enter the credit value and percent per annum (value percent): ";
    cin >> k >> p;
    cout << "Enter the profit per year (value): ";
    cin >> r;
    if (r > k * p / 100) {
        while (k > 0)
        {
            k = k + k * p / 100 - r;
            years += 1;
        }
        cout << "Yes, you will be able to pay the loan in " << years << " years";
        return 1;
    }
    else
    {
        cout << "You will not be able to repay the loan";
        return 0;
    }
}

int tFifthMilesInKilometers(void)
{
    float miles, kilometers, k;

    miles = 0;
    kilometers = 0;
    cout << "Введите что-то там";
    cout << "Enter the limit to which you want to build the table (km): ";
    cin >> k;
    cout << "Miles    Kilometrs" << endl;
    
    while (k > kilometers)
    {
        kilometers += 1;
        miles += 1;
        if (k > kilometers)
        {
        cout << fixed << setprecision(4) << left << setw(9) << kilometers * 0.6214 << kilometers << endl;
        }
        if (k > miles * 1.609344)
        cout << fixed << setprecision(4) << left << setw(9) << miles << miles * 1.609344 << endl;

        kilometers += 1;
        if (k > kilometers)
        {
        cout << fixed<< setprecision(4) << left << setw(9) << kilometers * 0.6214 << kilometers << endl;
        }
        else
        {
            return 1;
        }
        kilometers += 1;
        if (k > kilometers)
        {
        cout << fixed << setprecision(4) << left << setw(9) << kilometers * 0.6214 << kilometers << endl;
        }
        else
        {
            return 1;
        }
        miles += 1;
        if (k > miles * 1.609344)
        {
        cout << fixed<< setprecision(4) << left << setw(9) << miles << miles * 1.609344 << endl;
        }
    }
    return 1;
}
