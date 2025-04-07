#include <iostream>

using namespace std;

int main(void) {
  int n = 0xffffffff;
  cout << "0xffffffff " << n << endl;
  n = 0xfffffffe;
  cout << "0xfffffffe " << n << endl;
  n = 0xefffffff;
  cout << "0xefffffff " << n << endl;
  n = 0x7fffffff;
  cout << "0x7fffffff " << n << endl;
  n += 1;
  cout << "0x7fffffff + 1 " << n << endl;
  n = 0x80000000;
  cout << "0x80000000" << n << endl;
  return 0;
}
