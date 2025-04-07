#include <fstream>

using namespace std;

int readArray(const char *, int *, int);

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
