#include <iostream>

using namespace std;

// функция для проверки ввода снилса
bool correct_snils_input(char str[]);
// функция для записи строкового снилса в числовой массив
void str_snils_to_array(char *pstr, int *&parr);
// функия для подсчёта контрольной суммы
int calculate_control_number(int arr[]);

int main(void) {
  int const SIZE_SNILS = 14;                 // xxx-xxx-xxx yy
  int const SIZE_SNILS_STR = SIZE_SNILS + 1; // + 1 для знака окончания строки
  char str[SIZE_SNILS_STR] = {'\0'};

  cout << "Program for check correct snils" << endl;

  do {
    cout << "Please, enter the correct snils (xxx-xxx-xxx xx): " << endl;
    cin.getline(str, SIZE_SNILS_STR);
  } while (!correct_snils_input(str));

  int const SIZE_SNILS_NUMBERS = 11; // [x, x, x, x, x, x, x, x, x, y, y]

  int arr[SIZE_SNILS_NUMBERS] = {0};
  char *pstr = str;
  int *parr = arr;
  str_snils_to_array(pstr, parr);

  int control_number = arr[9] * 10 + arr[10];

  if (calculate_control_number(arr) == control_number) {
    cout << "Yes, your snils absolutely correct" << endl;
  } else {
    cout << "No, your control number not equals control sum of your snils "
         << endl;
  }

  return 0;
}

bool correct_snils_input(
    char str[]) { // проще было бы сделать маску, но я с ними не работал
  for (int i = 0; str[i] != '\0'; i++) {
    if (i == 3 || i == 7) { // места где в снилсе должны быть '-'
      if (str[i] != '-') {
        return false;
      } else
        continue;
    } else if (i == 11) { // место где в снилсе стоит ' '
      if (str[i] != ' ') {
        return false;
      } else
        continue;
    } else {
      if (str[i] > '9' || str[i] < '0') { // проверка на ввод цифры
        return false;
      } else
        continue;
    }
  }
  return true;
}

void str_snils_to_array(char *pstr, int *&parr) {
  while (*pstr != '\0') {
    if (*pstr != '-' && *pstr != ' ') {
      *parr = *pstr - '0';
      parr++;
    }
    pstr++;
  }
}

int calculate_control_number(int arr[]) {
  int sum = 0;
  int *parr = arr;
  for (int i = 9; i > 0; i--) {
    sum += (i) * *parr;
    parr++;
  }
  int c_number = sum % 101;
  return c_number;
}
