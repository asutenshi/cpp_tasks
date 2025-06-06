#include "geometry.h"
#include <cmath>

double calcDistance(const Point &pa, const Point &pb) {
  return sqrt((pb.x - pa.x) * (pb.x - pa.x) + (pb.y - pa.y) * (pb.y - pa.y));
}

double calcAreaBySides(double a, double b, double c) {
  double p2 = (a + b + c) / 2;
  if (p2 <= 0.0 || p2 <= a || p2 <= b || p2 <= c)
    return 0.0;
  return sqrt(p2 * (p2 - a) * (p2 - b) * (p2 - c));
}

bool checkTriangle(const Triangle &tr) {
  const Point *v = tr.vertexes;
  return 0 !=
         v[0].x * (v[1].y - v[2].y) +
             v[1].x * (v[2].y - v[0].y) + // проверка на коллинеарность точек
             v[2].x * (v[0].y - v[2].y);
}

double calcTrianglePerimeter(Triangle &tr) {
  Point *v = tr.vertexes;
  return tr.perimetr = calcDistance(v[0], v[1]) + calcDistance(v[1], v[2]) +
                       calcDistance(v[0], v[2]);
}

double calcTriangleArea(Triangle &tr) {
  Point *v = tr.vertexes;
  double a = calcDistance(v[0], v[1]);
  double b = calcDistance(v[1], v[2]);
  double c = calcDistance(v[2], v[0]);
  return tr.area = calcAreaBySides(a, b, c);
}
