<<<<<<< HEAD
#include <climits>
#include <cstdlib>
#include <ctime>
=======
>>>>>>> bebf488d22da3da9255ed5009774980736f401da
#include <iostream>

using namespace std;

int main(void) {
<<<<<<< HEAD
  int size = 10;
  int *arr = new int[size];
  int min_v = INT_MAX;

  srand(time(0));

  for (int i = 0; i < size; i++) {
    *(arr + i) = (rand() % 101) - 50;
    int value = *(arr + i);
    cout << value << endl;
    if (min_v >= value)
      min_v = value;
  }

  cout << "Min value: " << min_v << endl;

  delete[] arr;
=======
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
  delete[] arr;

>>>>>>> bebf488d22da3da9255ed5009774980736f401da
  return 0;
}
