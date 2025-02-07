#include <iostream>

using namespace std;

bool correct_snils_input(char str[]);
int control_number(int arr[]);

int main(void) {
  int const SIZE_SNILS = 14;           // xxx-xxx-xxx xx
  int const SIZE_CONTROL_NUMBERS = 9;  // xxxxxxxxxx
  int const SIZE_STR = SIZE_SNILS + 1; // для знака окончания строки
  char str[SIZE_STR] = {'\0'};

  cout << "Program for check correct snils" << endl;

  do {
    cout << "Please, enter the correct snils (xxx-xxx-xxx xx): " << endl;
    cin.getline(str, SIZE_STR);
  } while (!correct_snils_input(str));

  int arr[SIZE_CONTROL_NUMBERS] = {
      0}; // - 1 тк нам не нужен символ окончания строки
  char *pstr = str;
  int *parr = arr + SIZE_CONTROL_NUMBERS - 1;

  while (*pstr != ' ') {
    if (*pstr != '-') {
      *parr = *pstr - '0';
      parr--;
    }
    pstr++;
  }

  pstr = str + SIZE_STR - 3;
  int c_number = 0;

  cout << "pstr = " << *pstr << endl;
  c_number += 10 * (*pstr - '0');
  pstr++;
  cout << "pstr = " << *pstr << endl;
  c_number += *pstr - '0';

  cout << "str = " << str << " " << correct_snils_input(str) << endl;
  for (int i = 0; i < SIZE_CONTROL_NUMBERS; i++)
    cout << arr[i];
  cout << "control_number = " << control_number(arr) << endl;
  cout << "control_number = " << c_number << endl;

  return 0;
}

bool correct_snils_input(char str[]) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (i == 3 || i == 7) { // места где в снилсе должны быть '-'
      if (str[i] != '-') {
        cout << "here1" << endl;
        return false;
      } else
        continue;
    } else if (i == 11) { // место где в снилсе стоит ' '
      if (str[i] != ' ') {
        cout << "here2" << endl;
        return false;
      } else
        continue;
    } else {
      if (str[i] > '9' || str[i] < '0') { // проверка на ввод цифры
        cout << "here3" << endl;
        return false;
      } else
        continue;
    }
  }
  return true;
}

int control_number(int arr[]) {
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    sum += (i + 1) * arr[i];
  }
  int c_number = sum % 101;
  return c_number;
}
