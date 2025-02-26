#include "math.h"

double linearFind(double x1, double y1, double x2, double y2) {
  return x1 - y1 * (x2 - x1) / (y2 - y1);
}

double calcDeterminant3x3(double a[3][3]) {
  return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
         a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
         a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

double calcDeterminant2x2(double a[2][2]) {
  return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}

void minorMatrixFrom3x3(double matrix[3][3], int x, int y, double minor[2][2]) {
  int minor_row = 0;
  x--;
  y--;

  for (int i = 0; i < 3; i++) {
    if (i == x)
      continue;

    int minor_col = 0;
    for (int j = 0; j < 3; j++) {
      if (j == y)
        continue;
      minor[minor_row][minor_col] = matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
}

double algebraicAddition3x3(int x, int y, double matrix[3][3]) {
  int sign = (x + y) % 2 == 0 ? 1 : -1;
  double minor[2][2];
  minorMatrixFrom3x3(matrix, x, y, minor);
  return sign * calcDeterminant2x2(minor);
}

void calcReverseMatrix3x3(double in[3][3], double out[3][3]) {
  double determinant = calcDeterminant3x3(in);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      out[j][i] = algebraicAddition3x3(i + 1, j + 1, in) / determinant;
    }
  }
}

void createMatrixForQuadEqutation(double x1, double x2, double x3,
                                  double out[3][3]) {
  double x;
  for (int i = 0; i < 3; i++) {
    switch (i) {
    case 0:
      x = x1;
      break;
    case 1:
      x = x2;
      break;
    case 2:
      x = x3;
      break;
    default:
      x = 0;
      break;
    }
    for (int j = 0; j < 3; j++) {
      switch (j) {
      case 0:
        out[i][j] = x * x;
        break;
      case 1:
        out[i][j] = x;
        break;
      case 2:
        out[i][j] = 1;
        break;
      default:
        out[i][j] = 0;
        break;
      }
    }
  }
}

void mulMatrix3x1(double a[3][3], double b[3], double out[3]) {
  double temp;
  for (int i = 0; i < 3; i++) {
    temp = 0;
    for (int j = 0; j < 3; j++) {
      temp += a[i][j] * b[j];
    }
    out[i] = temp;
  }
}

double quadFind(double x1, double y1, double x2, double y2, double x3,
                double y3) {
  // X = A^-1 * B

  double a[3][3];
  createMatrixForQuadEqutation(x1, x2, x3, a);

  double rev_a[3][3];
  calcReverseMatrix3x3(a, rev_a);

  double b[3] = {y1, y2, y3};
  double x[3]; // x[0] - a, x[1] - b, x[2] - c
  mulMatrix3x1(rev_a, b, x);

  return -x[1] / 2 / x[0];
}
