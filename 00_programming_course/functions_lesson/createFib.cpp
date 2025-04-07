#include <iostream>

using namespace std;

int *createFib(const int);

int main(void) {
  const int FIB_NUMBER = 10;
  int *fibArr = createFib(FIB_NUMBER);

  cout << "Fibonachi numbers: ";

  for (int i = 0; i < FIB_NUMBER; i++)
    cout << fibArr[i] << ' ';
  cout << endl;

  delete[] fibArr;
  return 0;
}

int *createFib(const int FIB_NUMBER) {
  int *arr = new int[FIB_NUMBER];
  arr[0] = arr[1] = 1;
  for (int i = 2; i < FIB_NUMBER; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr;
}
