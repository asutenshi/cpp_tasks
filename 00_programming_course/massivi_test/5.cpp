#include <iostream>

using namespace std;

int main(void) {
  int arr[10][10] = {
      {1, 1, 1, 0, 0, 1, 0, 0, 1, 1}, {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
      {0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 0, 0, 1, 1},
      {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 0, 0, 0, 0}};
  int arr_copy[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      arr_copy[i][j] = 0;
    }
  }

  int count = 0;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (arr[i][j] == 1 && arr_copy[i][j] != 1) {
        count++;

        /*cout << "i=" << i << " j=" << j << endl;*/
        /*cout << "arr_copy[i][j]= " << arr_copy[i][j] << endl;*/
        /*for (int q = 0; q < 10; q++) {*/
        /*  for (int z = 0; z < 10; z++) {*/
        /*    cout << arr_copy[q][z] << ' ';*/
        /*  }*/
        /*  cout << endl;*/
        /*}*/

        int k = j;
        while (arr[i][k] == 1 && k < 10) {
          arr_copy[i][k] = 1;
          k++;
        }
        k--;
        int l = i;
        while (arr[l][j] == 1 && l < 10) {
          arr_copy[l][j] = 1;
          l++;
        }
        l--;
        for (int m = i; m <= l; m++) {
          for (int n = j; n <= k; n++) {
            arr_copy[m][n] = 1;
          }
        }
      }
    }
  }
  /*cout << endl;*/
  /*for (int i = 0; i < 10; i++) {*/
  /*  for (int j = 0; j < 10; j++) {*/
  /*    cout << arr_copy[i][j] << ' ';*/
  /*  }*/
  /*  cout << endl;*/
  /*}*/
  cout << "Count of rectangles: " << count << endl;
  return 0;
}
