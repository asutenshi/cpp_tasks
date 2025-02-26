#include "file.h"
#include <fstream>
#include <iostream>

using namespace std;

int countPoints(const char *fileName) {
  ifstream in(fileName);

  if (!in.is_open())
    return -1;

  double x, y;
  int i;

  for (i = 0;; i++) {
    in >> x >> y;
    if (in.fail())
      break;
  }
  return i;
}

bool checkCountPoints(int pointNum) {
  if (pointNum < 0) {
    cout << "Программа не получила ни одной точки" << endl;
    return false;
  } else if (pointNum < 4) {
    cout << "Программа получила менее 3 точек" << endl;
    return false;
  } else
    return true;
}

int countTriangles(int pointNum) {
  return (pointNum * (pointNum - 1) * (pointNum - 2) / 6);
}

bool readPoints(const char *fileName, Point *pointArray, int maxPointNum) {
  ifstream in(fileName);

  if (!in.is_open())
    return 0;

  for (int i = 0; i < maxPointNum; i++) {
    in >> pointArray[i];
    if (in.fail())
      return false;
  }
  return true;
}

istream &operator>>(istream &in, Point &p) {
  in >> p.x >> p.y;
  return in;
}

ostream &operator<<(ostream &out, const Point &p) {
  out << '(' << p.x << "; " << p.y << ')';
  return out;
}

ostream &operator<<(ostream &out, const Triangle &tr) {
  const Point *v = tr.vertexes;
  out << "A = " << v[0] << " B = " << v[1] << " C = " << v[2];
  return out;
}

bool writeTriangles(const char *fileName, const Triangle *trArray, int trNum,
                    bool sortByPerimeter) {
  ofstream out(fileName);

  if (!out.is_open()) {
    return false;
  }
  if (sortByPerimeter) {
    for (int i = 0; i < trNum; i++)
      out << "#" << i + 1 << ": " << trArray[i]
          << " perimetr = " << trArray[i].perimetr << endl;
  } else {
    for (int i = 0; i < trNum; i++)
      out << "#" << i + 1 << ": " << trArray[i] << " area = " << trArray[i].area
          << endl;
  }
  return true;
}
