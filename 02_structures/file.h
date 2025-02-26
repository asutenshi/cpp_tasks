#ifndef _FILE_H
#define _FILE_H

#include "geometry.h"
#include <iostream>

using namespace std;

int countPoints(const char *fileName);
bool checkCountPoints(int pointNum);
int countTriangles(int pointNum);
bool readPoints(const char *fileName, Point *pointArray, int maxPointNum);
bool writeTriangles(const char *fileName, const Triangle *trArray, int trNum,
                    bool sortByPerimeter);

istream &operator>>(istream &in, Point &p);
ostream &operator<<(ostream &out, const Point &p);
ostream &operator<<(ostream &out, const Triangle &tr);

#endif // !_FILE_H
