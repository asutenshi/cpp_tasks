#include <iostream>

using namespace std;

int main(void) {
  int size;

  do {
      cout << "Enter the n value (binary lenght number M): " << endl;
      cin >> size;
  } while(size <= 0);
  int *parr = new int[size];

  int *parr2 = new int[size + 1];
  *(parr2 + size) = 0;

  cin.ignore();

  cout << "Enter binary stracture of number M with " << size
       << " bits: " << endl;
  char *pstr = new char[size + 1];
  cin.getline(pstr, size + 1);

  for (int i = 0; i < size; i++) {
      if (*(pstr + size - i - 1) < '0' || *(pstr + size - i - 1) > '1') {
          cout << "In binary structure we can use only '0' and '1'" << endl;
          return -1;
      }
      *(parr + i) = *(pstr + size - i - 1) - '0';
      *(parr2 + i) = *(parr + i);
  }
  delete[] pstr;

  for (int i = 0; i < size; i++) {
      if (*(parr + i) == 0) {
        *(parr2 + i) = 1;
        break;
      } else {
        *(parr2 + i) = 0;
        if (i == size - 1)
            *(parr2 + i + 1) = 1;
      }
  }

  cout << "binary stracture of number M:    ";
  for (int i = size - 1; i >= 0; i--)
    cout << *(parr + i);
  
  cout << endl;

  cout << "binary stracture of number M+1: ";
  for (int i = size; i >= 0; i--)
    cout << *(parr2 + i);

  delete[] parr;
  delete[] parr2;
  return 0;
}
