#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int ROWS = 8;
const int COLS = 8;

void printBinary(int number);
void printMatrix(int matrix[ROWS][COLS]);
int calc_control_sum(int matrix[ROWS][COLS]);

int main() {

  srand(time(0));

  int matrix[ROWS][COLS];

  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      matrix[i][j] = rand() % 2;
    }
  }

  printMatrix(matrix);

  int trol_n = rand() % 64;

  cout << "Троль выбрал " << trol_n << " ячейку" << endl;

  int control_sum = calc_control_sum(matrix);

  cout << "Число доски: " << control_sum << endl;

  cout << "Число доски и число, которое выбрал троль :" << endl;
  printBinary(control_sum);
  printBinary(trol_n);

  int flip_coin = trol_n ^ control_sum;

  cout << "Первый программист перевернул " << flip_coin << " монетку" << endl;

  int i_flip_coin = flip_coin / 8;
  int j_flip_coin = flip_coin % 8;

  cout << "Положение первёрнутой монетки: " << i_flip_coin << " строка, "
       << j_flip_coin << " столбец" << endl;

  matrix[i_flip_coin][j_flip_coin] ^= 1;

  printMatrix(matrix);

  int control_sum2 = calc_control_sum(matrix);

  cout << "Второй программист выбрал " << control_sum2 << " ячейку" << endl;

  return 0;
}

void printBinary(int number) {
  int size = sizeof(number) * 8;

  for (int i = size - 1; i >= 0; --i) {
    cout << ((number >> i) & 1);
  }
  cout << endl;
}

void printMatrix(int matrix[ROWS][COLS]) {
  cout << "Шахматная доска:\n";
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}

int calc_control_sum(int matrix[ROWS][COLS]) {
  int control_sum = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (matrix[i][j] == 1) {
        control_sum ^= (i * 8 + j);
      }
    }
  }
  return control_sum;
}
