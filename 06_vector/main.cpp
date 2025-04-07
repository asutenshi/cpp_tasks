#include "iosif_flaviy.h"
#include "lineListCycle.h"
#include <chrono>
#include <iostream>

using namespace std;

int main(void) {
  try {
    int ns[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    for (int i = 0; i < sizeof(ns) / sizeof(ns[0]); i++) {
      auto start = chrono::high_resolution_clock::now();
      test_array_listCycle(ns[i], 2);
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = end - start;
      cout << "Функция выполнялась: " << elapsed.count() << " секунд" << endl;
    }
  } catch (LineListCycleException& e) {
    cout << "что-то пошло не так" << endl;
  }
  // test_array_listCycle(100, 2);
  return 0;
}
