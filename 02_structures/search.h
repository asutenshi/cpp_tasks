#ifndef _SEARCH_H
#define _SEARCH_H

#include "geometry.h"

void findAndInsert(Triangle *trArray, int length, const Triangle &tr,
                   bool sortByPerimeter);
void searchLargestTriangles(const Point *pointArray, int pointNum,
                            Triangle *trArray, int maxTrNum,
                            bool sortByPerimeter);
void clearPoint(Point &p);
void clearTriangle(Triangle &tr);

#endif // !_SEARCH_H
