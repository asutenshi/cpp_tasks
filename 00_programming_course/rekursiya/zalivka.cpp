#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int ROWS = 8;
const int COLS = 8;

void printMatrix(int matrix[ROWS][COLS]);
int zalivka(int matrix[ROWS][COLS], int m, int k);

int main() {

  srand(time(0));

  int matrix[ROWS][COLS];

  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      matrix[i][j] = rand() % 2;
    }
  }

  printMatrix(matrix);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << zalivka(matrix, i, j) << endl;
    }
  }

  return 0;
}

int zalivka(int matrix[ROWS][COLS], int m, int k) {
  if (m < 0 || m > ROWS - 1 || k < 0 || k > COLS - 1 || matrix[m][k] == 0)
    return 0;
  matrix[m][k] = 0;
  return 1 + zalivka(matrix, m - 1, k) + zalivka(matrix, m, k + 1) +
         zalivka(matrix, m + 1, k) + zalivka(matrix, m, k - 1);
}

void printMatrix(int matrix[ROWS][COLS]) {
  cout << "Матрица:\n";
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}
