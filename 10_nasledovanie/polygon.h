#ifndef _POLYGON_H
#define _POLYGON_H

#include "figure.h"
#include "point.h"
#include <string>
#include <vector>

class PolygonException {};

class Polygon : public Figure
{
    protected:
        std::vector<Point> points;
    public:
        Polygon();
        Polygon(std::vector<Point> points);
        Polygon(std::string filename);
        const std::vector<Point>& getPoints() const;
        double calc_area();
        double calc_perimeter();
        void name();
};

#endif