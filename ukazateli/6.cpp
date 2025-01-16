#include <iostream>

using namespace std;

int main(void) {
  int const SIZE_ARR = 10;
  int arr[SIZE_ARR] = {0};
  int *parr = arr;

  int n;
  do {
    cout << "Enter the number or 0 for quit input: ";
    cin >> n;
    *parr = n;
    parr++;
  } while (n != 0 && parr < arr + SIZE_ARR);

  /*for (int i = 0; i < SIZE_ARR && arr[i] != 0; i++) {*/
  /*  cout << i << " int = " << arr[i] << endl;*/
  /*}*/

  int *ps = arr;

  if (*ps == 0) {
    cout << "Ne bilo vvedeno ni odnogo chisla. Vse 1000 chisel = 0" << endl;
    return 1;
  }

  if (int *pcheck = arr + SIZE_ARR) {
    cout << "Vse 100 chisel != 0" << endl;
    return 2;
  }

  int *pe = arr + SIZE_ARR / 2;

  /*cout << "ps = " << ps - arr << " ; pe = " << pe - arr << endl;*/
  int length;
  while (!(*pe != 0 && *(pe + 1) == 0)) {
    length = pe - ps + 1;
    if (*pe == 0 && *(pe + 1) == 0) {
      pe -= length / 2;
    }
    else {
      ps += length;
      pe += length / 2;
    }
    /*cout << "ps = " << ps - arr << " ; pe = " << pe - arr << endl;*/
  }

  cout << "V stroke " << pe - arr + 1 << " ne nulevih elementa" << endl;

  return 0;
}
