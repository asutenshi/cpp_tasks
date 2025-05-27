#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "figure.h"
#include "point.h"


class Rectangle : public Figure
{
    protected:
        Point p1;
        Point p2;
        int height;
        int width;
    public:
        Rectangle();
        Rectangle(int height, int width);
        Rectangle(int x1, int y1, int x2, int y2);
        Rectangle(Point p1, Point p2);
        double calc_area();
        double calc_perimeter();
        void name();
};



#endif