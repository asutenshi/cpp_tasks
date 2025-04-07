#ifndef _RATIONAL_H
#define _RATIONAL_H

#include <iostream>

using namespace std;

class RationalException{};

class Rational {
    int numer;
    int denom;
    void simplify();
    public:
        Rational();
        Rational(int number);
        Rational(int n, int d);
        Rational& operator =(const Rational& r);
        /*
        Я реализовал геттеры и сеттеры т.к. начал реализовывать
        ввод/вывод до того, как узнал о friend. Пришлось все равно прописать
        friend для применения simplify при вводе, но сеттеры/геттеры оставил
        */
        int getNumer() const;
        int getDenom() const;
        void setNumer(int n);
        void setDenom(int d);
        Rational &operator += (const Rational &r);
        Rational operator + (const Rational &r) const;
        Rational &operator -= (const Rational &r);
        Rational operator - () const;
        Rational &operator *= (const Rational &r);
        Rational operator * (const Rational &r) const;
        Rational &operator /= (const Rational &r);
        Rational operator / (const Rational &r) const;
        Rational operator - (const Rational &r) const;
        Rational &operator ++();
        Rational operator ++(int);
        Rational &operator --();
        Rational operator --(int);
        bool operator ==(const Rational &r) const;
        bool operator !=(const Rational &r) const;
        bool operator >=(const Rational &r) const;
        bool operator >(const Rational &r) const;
        bool operator <=(const Rational &r) const;
        bool operator <(const Rational &r) const;
        operator int() const;
        operator double() const;
        Rational sqrt() const;
        Rational abs() const;
        friend istream &operator >> (istream &in, Rational &r);
        friend ostream &operator << (ostream &out, const Rational &r);
};

int findGCD(int a, int b); // greatest common divisor
int abs_bitwise(int x);
int sqrt_newton_int(int n);

#endif