#ifndef _ELLIPSE_H
#define _ELLIPSE_H

#include "figure.h"
#include "point.h"

class Ellipse : public Figure
{
    protected:
        Point c;
        double a;
        double b;
    public:
        Ellipse();
        Ellipse(int x, int y, double a, double b);
        Ellipse(Point c, double a, double b);
        double calc_area();
        double calc_perimeter();
        void name();
};

#endif