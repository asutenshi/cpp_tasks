#include <iostream>

using namespace std;

int main(void) {
  int a[10];
  int *p = a;

  for (int i = 0; i < 10; i++) {
    *p = i;
    cout << *p << endl;
    p++;
  }

  int size = 10;
  int *arr = new int[size];

  for (int i = 0; i < size; i++) {
    *(arr + i) = i + 1;
  }

  return 0;
}
