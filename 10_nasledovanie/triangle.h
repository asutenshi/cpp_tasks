#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "figure.h"
#include "point.h"

class TrianglException {};

class Triangle : public Figure
{
    protected:
        Point p1, p2, p3;
        double a, b, c;
    public:
        Triangle();
        Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
        Triangle(int a, int b, int c);
        Triangle(Point p1, Point p2, Point p3);
        double calc_area();
        double calc_perimeter();
        void name();
};

#endif