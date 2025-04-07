#include <assert.h>
#include <fstream>
#include <iostream>

using namespace std;

int findMax(const int *, int);
int readArray(const char *, int *, int);

int main(void) {
  char filename[9] = {'d', 'a', 't', 'a', '.', 't', 'x', 't', '\0'};
  int const MAX_LENGTH = 10;
  int *arr = new int[MAX_LENGTH];
  readArray(filename, arr, MAX_LENGTH);

  cout << "Data.txt: " << endl;
  for (int i = 0; i < MAX_LENGTH; i++) {
    cout << "arr[" << i << "] = " << arr[i] << endl;
  }

  cout << "Max element in data.txt = " << findMax(arr, MAX_LENGTH) << endl;
  delete[] arr;
  return 0;
}

int findMax(const int *arr, int length) {
  assert(length > 0);
  int max = arr[0];

  for (int i = 1; i < length; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

int readArray(const char *fileName, int *arr, int maxLength) {
  ifstream in(fileName);

  if (!in.is_open())
    return 0;

  int elem;
  for (int i = 0; i < maxLength; i++) {
    in >> elem;
    if (in.fail())
      return i;
    arr[i] = elem;
  }
  return maxLength;
}
