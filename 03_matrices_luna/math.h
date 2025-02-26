#ifndef _MATH_H
#define _MATH_H

double linearFind(double x1, double y1, double x2, double y2);
double calcDeterminant3x3(double a[3][3]);
double calcDeterminant2x2(double a[2][2]);
void minorMatrixFrom3x3(double matrix[3][3], int x, int y, double minor[2][2]);
double algebraicAddition3x3(int x, int y, double matrix[3][3]);
void calcReverseMatrix3x3(double in[3][3], double out[3][3]);
void mulMatrix3x1(double a[3][3], double b[3], double out[3]);
void createMatrixForQuadEqutation(double x1, double x2, double x3,
                                  double out[3][3]);
double quadFind(double x1, double y1, double x2, double y2, double x3,
                double y3);

#endif //
