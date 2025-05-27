#include "polygon.h"
#include "point.h"
#include <fstream>

Polygon::Polygon()
{
    this->points.push_back(Point(0, 0));
}

Polygon::Polygon(std::vector<Point> points)
{
    for (Point p : points)
    {
        this->points.push_back(p);
    }
}

Polygon::Polygon(std::string filename)
{
    std::ifstream in(filename);
    if (!in.is_open())
    {
        std::cout << "File is not opened" << std::endl;
        throw PolygonException();
    }

    int n;
    in >> n;

    for (int i = 0; i < n && !in.eof(); i++)
    {
        Point p;
        in >> p;

        if (in.fail())
        {
            std::cout << "Failed to read point #" << i << std::endl;
            throw PolygonException();
        }

        points.push_back(p);
    }

    if (points.size() < 3)
    {
        std::cout << "Not enough points to create a polygon" << std::endl;
        throw PolygonException();
    }
}

const std::vector<Point>& Polygon::getPoints() const
{
    return this->points;
}

double Polygon::calc_area()
{
    if (points.size() < 3)
        return 0;
    
    double area = 0.0;
    int n = points.size();

    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += points[i].getX() * points[j].getY();
        area -= points[j].getX() * points[i].getY();
    }

    return std::abs(area) / 2.0;
}

double Polygon::calc_perimeter()
{
    if (points.size() < 2)
        return 0;

    double perimeter = 0.0;
    int n = points.size();

    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;

        perimeter += getDistance(points[i], points[j]);
    }

    return perimeter;
}

void Polygon::name()
{
    std::cout << "Polygon";
}

