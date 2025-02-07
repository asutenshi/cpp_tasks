#ifndef _SEARCH_H
#define _SEARCH_H

#include "geometry.h"

void findAndInsert(Triangle *trArray, int length, const Triangle &tr);
void searchLargestTriangles(const Point *pointArray, int pointNum,
                            Triangle *trArray, int maxTrNum);
void clearPoint(Point &p);
void clearTriangle(Triangle &tr);

#endif // !_SEARCH_H
