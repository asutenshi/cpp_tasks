#include "point.h"
#include <cmath>

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

double getDistance(Point p1, Point p2)
{
    double dx = (p2.getX() - p1.getX());
    double dy = (p2.getY() - p2.getY());
    return std::sqrt(dx*dx + dy*dy);
}

std::istream& operator>>(std::istream& in, Point &p)
{
    in >> p.x >> p.y;
    return in;
}