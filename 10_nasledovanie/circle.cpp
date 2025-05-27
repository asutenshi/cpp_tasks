#include "circle.h"
#include <cmath>

Circle::Circle()
{
    this->c = Point(0, 0);
    this->r = 0;
}

Circle::Circle(Point c, double r)
{
    this->c = c;
    this->r = r;
}

Circle::Circle(int x, int y, double r)
{
    this->c = Point(x, y);
    this->r = r;
}

double Circle::calc_area()
{
    return M_PI * r * r;
}

double Circle::calc_perimeter()
{
    return 2 * M_PI * r;
}

void Circle::name()
{
    std::cout << "Circle";
}