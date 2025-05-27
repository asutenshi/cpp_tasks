#ifndef _POINT_H
#define _POINT_H

#include <fstream>

class Point
{
    private:
        int x, y;
    public:
        Point();
        Point(int x, int y);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        friend std::istream& operator>>(std::istream& in, Point &p);
};

double getDistance(Point p1, Point p2);

#endif