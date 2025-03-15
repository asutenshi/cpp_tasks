#include "array.h"
#include "iosif_flaviy.h"
#include <iostream>
#include <chrono>

using namespace std;

int main(void) {
    try {
        int ns[] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
        for (int i = 0; i < sizeof(ns) / sizeof(ns[0]); i++) {
            auto start = chrono::high_resolution_clock::now();
            test_array(ns[i], 2);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;
            std::cout << "Функция выполнялась: " << elapsed.count() << " секунд" << endl;
        }
    } catch (ArrayException& e) {
        cout << "Возникла непредвиденная ошибка" << endl;
    }
}