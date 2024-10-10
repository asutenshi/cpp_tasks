#include <iostream>
#include <iomanip>

using namespace std;

int tForthCommerce();
int tFifthMilesInKilometers();

int main(void)
{
    tFifthMilesInKilometers();
    return 0;
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
