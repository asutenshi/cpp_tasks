#ifndef _EQUATIONS_H
#define _EQUATIONS_H

#include "rational.h"

Rational linear_eq(Rational k, Rational b);
void quad_eq(Rational a, Rational b, Rational c, Rational out[2]);

#endif