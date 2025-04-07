#include <conio.h>
#include <iomanip>
#include <iostream>

using namespace std;

void myArray(int size);

int main(void) {
  int size = 100000; // можем использовать не константу
  /*int *ptr = new int[size];*/

  int for_size = 10000;

  for (int i = 0; i < size; i++) {
    myArray(size);
    if (i % 100 == 0) {
      _getch();
    }
  }

  /*for (int i = 0; i < size; i++) {*/
  /*  cout << "ptr(" << i << ") = " << setw(2) << setfill(' ') << ptr[i]*/
  /*       << "\tadress p[" << ptr[i] << "] ==" << &ptr[i] << endl;*/
  /*}*/
  /**/
  /*cout << "adress ptr = " << &ptr << " value ptr = " << ptr << endl;*/
}

void myArray(int size) {
  int *ptr = new int[size];
  /*int ptr[100000];*/

  for (int i = 0; i < size; i++) {
    ptr[i] = i + 1;
  }

  delete[] ptr;
}
