#include "file.h"
#include "search.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  if (argc < 3) {
    cout << "Запуск: Triangles.exe inf.txt outf.txt" << endl;
    return -1;
  }

  /*int inputType = 0;*/
  /**/
  /*cout << "Программа для поиска треугольников с самой большой площадью" << endl;*/
  /*cout << "Необходимо выбрать способ ввода координат треугольника" << endl*/
  /*     << "Ручной ввод (1)" << endl*/
  /*     << "Чтение из файла (2)" << endl;*/
  /**/
  /*do {*/
  /*  cout << "Введите способ ввода (1 или 2): " << endl;*/
  /*  cin >> inputType;*/
  /*} while (inputType != 1 && inputType != 2);*/

  const char *inFileName = argv[1];
  const char *outFileName = argv[2];
  int pointNum = countPoints(inFileName);

  if (pointNum < 0) {
    cout << "Входной файл не существует" << endl;
    return -2;
  } else if (pointNum < 4) {
    cout << "Входной файл слишком мал" << endl;
    return -3;
  }

  Point *pointArray = new Point[pointNum];
  if (!readPoints(inFileName, pointArray, pointNum)) {
    cout << "Неизвестная ошибка при вводе точек" << endl;
    return -3;
  }

  for (int i = 0; i < 9; i++) {
    cout << "p" << i << " = " << *(pointArray + i) << endl;
  }

  const int maxTrNum = 3;
  Triangle trArray[maxTrNum];
  searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum);

  if (!writeTriangles(outFileName, trArray, maxTrNum)) {
    cout << "Не удалось записать результат" << endl;
    return -4;
  }
  cout << "Программа успешно завершена" << endl;
  delete[] pointArray;
  return 0;
}
