#include <iostream>

using namespace std;

void symmetry(int*& pstart, int*& pend, int arr[], int const SIZE_ARR);
void type_arr(int*& pstart, int*& pend);

int main(void) {
  int const SIZE_ARR = 20;
  int arr[] = {10, 10, 3, 4, 4, 3, 2, 1, 5, 6, 5, 4, 3, 8, 9, 8, 7, 6, 22, 22};
  int *pcore =
      arr;     // pcore - будет искать ядро симметрии вида: ..yxy.. или ..yxxy..
  int *pstart; // point start - будет указывать на начало симметрии
  int *pend;   // point end - будет указывать на конец симметрии

  for (int i = 0; i < SIZE_ARR - 1; i++) {
    if (*(pcore - 1) == *(pcore + 1) && pcore != arr) {
      cout << "pcore = " << *pcore << endl;
      pstart = pcore - 1;
      pend = pcore + 1;
      symmetry(pstart, pend, arr, SIZE_ARR);
      type_arr(pstart, pend);
    } else if (*pcore == *(pcore + 1)) {
      cout << "pcore = " << *pcore << endl;
      pstart = pcore;
      pend = pcore + 1;
      symmetry(pstart, pend, arr, SIZE_ARR);
      type_arr(pstart, pend);
    }
    pcore++;
  }
  return 0;
}


void symmetry(int*& pstart, int*& pend, int arr[], int const SIZE_ARR) {
  while (pstart - 1 >= arr && pend + 1 <= arr + SIZE_ARR && *(pstart - 1) == *(pend + 1)) {
    pstart--;
    pend++;
  }
}

void type_arr(int*& pstart, int*& pend) {
  while (pstart <= pend) {
    cout << *pstart;
    pstart++;
  }
  cout << endl;
}
