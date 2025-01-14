#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(void) {
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
  return 0;
}
