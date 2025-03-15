#include "iosif_flaviy.h"
#include <iostream>

using namespace std;

void test_array(int N, int k) {
    Array arr(N);
    for (int i = 1; i <= N; i++)
        arr.insert(i);
    int i = 0;
    k--;
    while (arr.getSize() > 1) {
//        cout << arr << endl << i << endl << endl;
        if (i + k >= arr.getSize())
            i = i + k - arr.getSize();
        else
            i += k;
        arr.remove(i);
        if (i == arr.getSize())
            i--;
    }
    cout << "test_array(N = " << N << ", k = " << (k + 1) << ") = " << arr[0] << endl;
}