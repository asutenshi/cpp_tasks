#include "field.h"
#include <iostream>

using namespace std;

int main(void) {
  Field field(true);
  while (!field.isOver()) {
    field.print();
    cout << "Ходит " << (field.isRedTurnNow() ? "красный" : "желтый")
         << " игрок, введите ход (1-7) " << endl;
    int column;
    cin >> column;
    field.makeTurn(column);
  }
  field.printResult();

  return 0;
}
