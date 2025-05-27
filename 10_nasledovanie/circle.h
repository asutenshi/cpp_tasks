#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "figure.h"
#include "point.h"

class Circle : public Figure
{
    protected:
        Point c;
        double r;
    public:
        Circle();
        Circle(Point c, double r);
        Circle(int x, int y, double r);
        double calc_area();
        double calc_perimeter();
        void name();

};

#endif