#include "rectangle.h"

Rectangle::Rectangle()
{
    this->p1 = Point(0, 0);
    this->p2 = Point(0, 0);
    height = 0;
    width = 0;
}

Rectangle::Rectangle(int height, int width)
{
    this->p1 = Point(0, height);
    this->p2 = Point(width, 0);
    this->height = height;
    this->width = width;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
    this->p1 = Point(x1, y1);
    this->p2 = Point(x2, y2);
    height = abs(p2.getY() - p1.getY());
    width = abs(p2.getX() - p1.getX());
}

Rectangle::Rectangle(Point p1, Point p2)
{
    this->p1 = p1;
    this->p2 = p2;
    height = abs(p2.getY() - p1.getY());
    width = abs(p2.getX() - p1.getX());
}

double Rectangle::calc_area()
{
    return height * width;
}

double Rectangle::calc_perimeter()
{
    return 2 * (height + width);
}

void Rectangle::name()
{
    std::cout << "Rectangle" << std::endl;
}