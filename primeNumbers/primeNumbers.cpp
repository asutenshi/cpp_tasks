#include <fstream>
#include <iostream>
using namespace std;

int main(void) {
  ofstream out("prime.txt");  // Открываем файл для вывода
  const int PRIME_NUM = 1000; // До какого числа ищем
  int primeFound = 0;         // Сколько простых чисел уже нашли
  int primeArray[PRIME_NUM];  // Инициилизируем массив
  int current = 2;            // Текущее число (0 и 1 не нужно проверять)
  int limit = 2;              // Последний проверяемый делитель
  bool isPrime = true;        // Признак простоты

  while (primeFound < PRIME_NUM) {
    if ((limit + 1) * (limit + 1) <= current) {
      limit++;
    }
    for (int i = 0; i < primeFound && primeArray[i] <= limit; i++) {
      if (current % primeArray[i] == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      out << current << endl;
      primeArray[primeFound++] = current;
    }
    isPrime = true;
    current++;
  }
  return 0;
}
