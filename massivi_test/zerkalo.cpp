#include <iostream>

using namespace std;

int main(void) {
  int const SIZE_ARR = 20;
  int arr[] = {1, 2, 3, 2, 1, 3, 4, 5, 6, 5, 4, 3, 8, 9, 9, 8, 3, 4, 5, 1};
  int *pcore =
      arr;     // pcore - будет искать ядро симметрии вида: ..yxy.. или ..yxxy..
  int *pstart; // point start - будет указывать на начало симметрии
  int *pend;   // point end - будет указывать на конец симметрии

  for (int i = 0; i < SIZE_ARR - 1; i++) {
    if (*(pcore - 1) == *(pcore + 1) && pcore != arr) {
      pstart = pcore - 1;
      pend = pcore + 1;
    } else if (*pcore == *(pcore + 1)) {
      if (pcore == arr) {
        ...; // симметрия вида xx в самом начале массива
      } else if (pcore == arr + SIZE_ARR - 1) {
        ...; // симметрия вида xx в самом конце массива
      }
      pstart = pcore - 1;
      pend = pcore + 2;
    }
  }
  return 0;
}

void symmetry(int *pstart, int *pend, int arr[], int const SIZE_ARR) {

  if (*pstart == *pend && pstart - 1 >= arr && pend + 1 <= arr + SIZE_ARR) {
    pstart--;
    pend++;
  } else {
    pstart++; // тк
    pend--;
  }
}
