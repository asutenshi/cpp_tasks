#include "equations.h"

Rational linear_eq(Rational k, Rational b) {
    return (-b) / k;
}

void quad_eq(Rational a, Rational b, Rational c, Rational out[2]) {
    Rational d = b * b - (Rational)(4) * a * c;
    if (d < (Rational)(0)) {
        cout << "Дескриминант < 0, корней нет" << endl;
        return;
    }
    out[0] = ((-b) + d.sqrt()) / (Rational)(2) * a;
    out[1] = ((-b) - d.sqrt()) / (Rational)(2) * a;
}