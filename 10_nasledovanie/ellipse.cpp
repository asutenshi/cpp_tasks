#include "ellipse.h"
#include <cmath>

Ellipse::Ellipse()
{
    this->c = Point(0, 0);
    this->a = 0;
    this->a = 0;
}

Ellipse::Ellipse(int x, int y, double a, double b)
{
    this->c = Point(x, y);
    this->a = a;
    this->a = b;
}

Ellipse::Ellipse(Point c, double a, double b)
{
    this->c = c;
    this->a = a;
    this->a = b;
}

double Ellipse::calc_area()
{
    return M_PI * a * b;
}

double Ellipse::calc_perimeter()
{
    double h = ((a - b) / (a + b)) * ((a - b) / (a + b));
    return M_PI * (a + b) * (1 + 3 * h / (10 + sqrt(4 - 3*h)));
}

void Ellipse::name()
{
    std::cout << "Ellipse";
}