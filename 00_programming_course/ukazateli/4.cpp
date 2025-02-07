#include <iostream>

using namespace std;

int main(void) {
  int const N = 80;
  char str[N + 1];
  char *p1 = str;
  char *p2 = p1 + 1;

  cout << "Enter the string and press enter" << endl;
  cin.getline(str, 80);
}
