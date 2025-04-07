#ifndef _GEOMETRY_H
#define _GEOMETRY_H

struct Point {
  double x, y;
};

struct Triangle {
  Point vertexes[3];
  double area;
  double perimetr;
};

double calcDistance(const Point &pa, const Point &pb);
double calcAreaBySides(double a, double b, double c);
bool checkTriangle(const Triangle &tr);
double calcTrianglePerimeter(Triangle &tr);
double calcTriangleArea(Triangle &tr);

#endif // !_GEOMETRY_H
