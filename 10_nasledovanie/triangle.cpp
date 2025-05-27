#include "triangle.h"
#include "point.h"
#include <cmath>

Triangle::Triangle()
{
    this->p1 = Point(0, 0);
    this->p2 = Point(0, 0);
    this->p3 = Point(0, 0);
    this->a = 0;
    this->b = 0;
    this->c = 0;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    this->p1 = Point(x1, y1);
    this->p2 = Point(x2, y2);
    this->p3 = Point(x3, y3);
    this->a = getDistance(p1, p2);
    this->b = getDistance(p1, p3);
    this->c = getDistance(p2, p3);
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->a = getDistance(p1, p2);
    this->b = getDistance(p1, p3);
    this->c = getDistance(p2, p3);
}

Triangle::Triangle(int a, int b, int c)
{
    this->p1 = Point(0, 0);
    this->p2 = Point(0, 0);
    this->p3 = Point(0, 0);
    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::calc_area()
{
    int p = this->calc_perimeter();
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::calc_perimeter()
{
    return a + b + c;
}

void Triangle::name()
{
    std::cout << "Triangle" << std::endl;
}