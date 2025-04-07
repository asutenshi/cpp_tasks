#include "rational.h"
#include <climits>
#include <iostream>

using namespace std;

Rational::Rational() {
    numer = 0;
    denom = 1;
}

Rational::Rational(int number) {
    numer = number;
    denom = 1;
}

Rational::Rational(int n, int d) {
    numer = n;
    denom = d;
    simplify();
}

Rational& Rational::operator =(const Rational& r)
{
    if (r.getNumer() > INT_MAX/r.getDenom())
    {
        throw RationalException();
    }
    numer = r.numer;
    denom = r.denom;
    simplify();
    return *this;
}

int Rational::getNumer() const {
    return numer;
}

int Rational::getDenom() const {
    return denom;
}

void Rational::setNumer(int n) {
    numer = n;
}

void Rational::setDenom(int d) {
    if (d != 0) 
        denom = d;
    else {
        setNumer(0);
        cout << "Знаменатель не может быть = 0" << endl;
    }
}

int abs_bitwise(int x) {
    int mask = x >> 31;
    return (x ^ mask) - mask;
}

int findGCD(int a, int b) {
    a = abs_bitwise(a);
    b = abs_bitwise(b);
    while (a != 0 && b != 0) {
        if (a > b)
        a %= b;
        else
        b %= a;
    }
    return(a + b);
}

void Rational::simplify() {
    int gcd = findGCD(getNumer(), getDenom());
    setNumer(getNumer() / gcd);
    setDenom(getDenom() / gcd);
}

Rational &Rational::operator += (const Rational &r) {
    numer = (numer*r.denom + denom * r.numer);
    denom *= r.denom;
    simplify();
    return *this;
}

Rational Rational::operator + (const Rational &r) const {
    Rational res(*this);
    return res += r;
}

Rational &Rational::operator -= (const Rational &r) {
    return (*this += (-r));
}

Rational Rational::operator - (const Rational &r) const {
    return (*this + (-r));
}

Rational &Rational::operator *= (const Rational &r) {
    numer = numer * r.numer;
    denom = denom * r.denom;
    simplify();
    return *this;
}

Rational Rational::operator * (const Rational &r) const {
    Rational res(*this);
    return res *= r;
}

Rational &Rational::operator /= (const Rational &r) {
    Rational temp(r.getDenom(), r.getNumer());
    return *this *= temp;
}

Rational Rational::operator / (const Rational &r) const {
    Rational temp(r.getDenom(), r.getNumer());
    return *this * temp;
}

Rational Rational::operator - () const {
    Rational r(-numer, denom);
    return r;
}

Rational &Rational::operator ++() {
    numer += denom;
    return *this;
}

Rational Rational::operator ++(int) {
    Rational r(*this);
    numer += denom;
    return r;
}

Rational &Rational::operator --() {
    numer -= denom;
    return *this;
}

Rational Rational::operator --(int) {
    Rational r(*this);
    numer -= denom;
    return r;
}

bool Rational::operator ==(const Rational &r) const {
    return (numer == r.getNumer()) && (denom == r.getDenom());
}

bool Rational::operator !=(const Rational &r) const {
    return !(*this == r);
}

bool Rational::operator >(const Rational &r) const {
    return getNumer() * r.getDenom() > getDenom() * r.getNumer();
}

bool Rational::operator <(const Rational &r) const {
    return r > *this;
}

bool Rational::operator >=(const Rational &r) const {
    return (*this > r) || (*this == r);
}

bool Rational::operator <=(const Rational &r) const {
    return !(*this > r);
}

Rational::operator int() const {
    return getNumer() / getDenom();
}

Rational::operator double() const {
    return (double(getNumer())) / getDenom();
}

int sqrt_newton_int(int n) {
    if (n < 0) {
        cout << "Нельзя вычислить корень из отрицательного числа n = " << n << endl;
        return -1;
    }
    if (n == 0)
        return 0;
    double x = (double)n;

    for (int i = 0; i < 10; i++) {
        x = (x + ((double) n) / x) / 2.0;
    }

    return (int)(x + 0.5);
}

Rational Rational::abs() const {
    return Rational(abs_bitwise(getNumer()), abs_bitwise(getDenom()));
}

Rational Rational::sqrt() const {
    Rational x(*this);
    Rational e(1, 10000);
    Rational x_prev(*this);
    x_prev++;
    while ((x_prev - x).abs() > e)
    {
        cout << x << endl;
        x_prev = x;
        try
        {
            x = Rational(1, 2) * (x + (*this / x));
        } catch (RationalException& e)
        {
            break;
        }
    }
    return x;
}

istream &operator >> (istream &in, Rational &r) {
    int n, d;
    in >> n >> d;
    r.setNumer(n);
    r.setDenom(d);
    r.simplify();
    return in;
}

ostream &operator << (ostream &out, const Rational &r) {
    out << r.getNumer() << '/' << r.getDenom();
    return out;
}