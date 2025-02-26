#include "field.h"
#include <iomanip>
#include <iostream>

using namespace std;

Field::Field(bool isRedFirst) { clear(isRedFirst); }

const int DIR_NUMBER = 4;
const int di[] = {1, 0, 1, 1};
const int dj[] = {0, 1, -1, 1};
const int WIN_LENGTH = 4;

void Field::checkWinner() {
  for (int i = 0; i < FIELD_WIDTH; i++)
    for (int j = 0; j < FIELD_HEIGHT; j++) {
      Cell start = cells[i][j];
      if (start == EMPTY)
        continue;
      for (int dir = 0; dir < DIR_NUMBER; dir++) {
        int length = 0, iline = i, jline = j;
        while (++length < WIN_LENGTH) {
          iline += di[dir];
          jline += dj[dir];
          if (iline < 0 || iline >= FIELD_WIDTH || jline < 0 ||
              jline >= FIELD_HEIGHT)
            break;
          if (cells[iline][jline] != start)
            break;
        }
        if (length == WIN_LENGTH) {
          winner = start;
          return;
        }
      }
    }
}

bool Field::isOver() const {
  if (winner != EMPTY)
    return true;
  for (int i = 0; i < FIELD_WIDTH; i++)
    for (int j = 0; j < FIELD_HEIGHT; j++)
      if (getCell(i, j) == EMPTY)
        return false;
  return true;
}

bool Field::isWon(bool red) const {
  Cell cell = red ? RED : YELLOW;
  return cell == winner ? true : false;
}
bool Field::isRedTurnNow() const { return isRedTurn; }
Cell Field::getCell(int i, int j) const { return cells[i][j]; }

void Field::clear(bool isRedFirst) {
  isRedTurn = isRedFirst;
  winner = EMPTY;

  for (int i = 0; i < FIELD_WIDTH; i++) {
    for (int j = 0; j < FIELD_HEIGHT; j++) {
      cells[i][j] = EMPTY;
    }
  }
}

bool Field::makeTurn(int column) {
  if (winner != EMPTY || column < 1 || column > FIELD_WIDTH)
    return false;
  int i = column - 1;
  for (int j = 0; j < FIELD_HEIGHT; j++)
    if (cells[i][j] == EMPTY) {
      cells[i][j] = isRedTurn ? RED : YELLOW;
      checkWinner();
      isRedTurn = !isRedTurn;
      return true;
    }
  return false;
}

void Field::print() const {
  cout << setw(FIELD_WIDTH * 2) << setfill('#') << '\n';
  for (int i = FIELD_HEIGHT - 1; i >= 0; i--) {
    for (int j = 0; j < FIELD_WIDTH; j++) {
      if (cells[j][i] != EMPTY)
        cout << (cells[j][i] == RED ? "К" : "Ж") << ' ';
      else
        cout << '0' << ' ';
    }
    cout << '\n';
  }
  cout << setw(FIELD_WIDTH * 2) << setfill('#') << '\n';
}

void Field::printResult() const {
  cout << endl;
  cout << setw(23) << setfill('#') << '\n';
  cout << " Победитель - " << (isWon(true) ? "Красные" : "Жeлтые") << '\n';
  cout << setw(23) << setfill('#') << '\n';
  print();
}
