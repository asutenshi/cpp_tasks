#include <climits>
#include <iostream>

using namespace std;

int main(void) {
  double n = -128.0;
  int i;
  long long int lli;
  cout << "size n = " << sizeof(n) << "\tn = " << n << endl;
  if (sizeof(n) == 4) {
    i = *(int *)&n & 0x7fffffff;
    n = *(float *)&i;
  }
  if (sizeof(n) == 8) {
    lli = *(long long int *)&n & 0x7fffffffffffffff;
    n = *(double *)&lli;
  }
  cout << "size n = " << sizeof(n) << "\t|n| = " << n << endl;

  return 0;
}
