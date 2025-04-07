#include <iostream>

using namespace std;

int main(void) {
  int const SIZE = 15;
  int a[SIZE] = {10, 12, 13, 22, 55, 21, 66, 22, 92, 91, 2, 1, 70, 10, 12};
  int k = 0;
  int max_k = 0;

  for (int i = 0; i < SIZE - 1; i++) {
    if (a[i] < a[i + 1]) {
      k++;
      for (int j = 1; j < SIZE - 1; j++) {
        if ((j % 2 == 0 && a[i + j] < a[i + j + 1]) ||
            (j % 2 != 0 && a[i + j] > a[i + j + 1])) {
          k++;
        } else {
          k++;
          if (max_k <= k) {
            max_k = k;
          }
          k = 0;
          i = i + j - 1;
          break;
        }
      }
    }
  }
  cout << "Max_k = " << max_k << endl;
  return 0;
}
