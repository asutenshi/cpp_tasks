#include "file.h"
#include "geometry.h"
#include "search.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  if (argc < 3) {
    cout << "Запуск: Triangles.exe inf.txt outf.txt" << endl;
    return -1;
  }

  bool inputType;
  cout << "Программа для поиска треугольников с самой большой "
          "площадью/периметром"
       << endl;
  cout << "Необходимо выбрать способ ввода координат треугольника" << endl
       << "Ввод из файла (0)" << endl
       << "Ручной ввод (1)" << endl;
  do {
    cout << "Введите способ ввода (0 или 1): " << endl;
    cin >> inputType;
  } while (inputType && !inputType);

  int pointNum = 0;
  Point *pointArray;

  const char *inFileName = argv[1];
  const char *outFileName = argv[2];

  if (inputType) {
    do {
      cout << "Введите количество точек для ввода (не менее 3): ";
      cin >> pointNum;
    } while (pointNum <= 3);
    pointArray = new Point[pointNum];
    cout << "Последовательно введите " << pointNum << " точек/ки" << endl;
    for (int i = 0; i < pointNum; i++) {
      cout << i + 1 << "# точка (x y enter): ";
      cin >> pointArray[i];
    }
  } else {
    pointNum = countPoints(inFileName);
    pointArray = new Point[pointNum];
    if (!readPoints(inFileName, pointArray, pointNum)) {
      cout << "Неизвестная ошибка при вводе точек" << endl;
      return -3;
    }
    if (!checkCountPoints(pointNum)) {
      return -2;
    }
  }

  bool sortByPerimetr;
  do {
    cout << "Вы хотите отсортировать треугольники по площади или по "
            "периметру? "
            "(0 - площадь, 1 - периметр)"
         << endl;
    cin >> sortByPerimetr;
  } while (sortByPerimetr && !sortByPerimetr);

  int maxTrNum = 0;
  do {
    cout << "Введите кол-во треугольников на вывод (не более "
         << countTriangles(pointNum) << ')' << endl;
    cin >> maxTrNum;
  } while (maxTrNum < 0);
  Triangle *trArray = new Triangle[maxTrNum];

  searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum,
                         sortByPerimetr);

  if (!writeTriangles(outFileName, trArray, maxTrNum, sortByPerimetr)) {
    cout << "Не удалось записать результат" << endl;
    return -4;
  }
  cout << "Программа успешно завершена" << endl;
  delete[] pointArray;
  delete[] trArray;
  return 0;
}
