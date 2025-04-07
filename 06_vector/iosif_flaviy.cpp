#include "iosif_flaviy.h"
#include <iostream>
#include "array.h"
#include "lineListCycle.h"
#include "lineListCycleElem.h"

using namespace std;

void test_array(int N, int k) {
    Array arr(N);
    for (int i = 1; i <= N; i++)
        arr.insert(i);
    int i = 0;
    k--;
    while (arr.getSize() > 1) {
        if (i + k >= arr.getSize())
            i = (i + k) % arr.getSize();
        else
            i += k;
        arr.remove(i);
    }
    cout << "test_array(N = " << N << ", k = " << (k + 1) << ") = " << arr[0] << endl;
}

void test_array_listCycle(int N, int k) {
    try {

        LineListCycle<int> list;
        for (int i = N; i >= 1; i--)
            list.insertFirst(i);
        LineListCycleElem<int>* it = list.getStart();
        for (int i = 0; i < k-2; i++)
            it = it->getNext();
        // cout << list << endl;
        while (list.getSize() > 1)
        {
            list.deleteAfter(it);
            for (int i = 0; i < k-1; i++)
                it = it->getNext();
            // cout << list << endl;
            // cout << it->getData() << endl;
        }
        cout << "test_array_listCycle(N = " << N << ", k = " << (k) << ") = " << list << endl;
    } catch (LineListCycleException& e)
    {
        cout << "что-то пошло не так" << endl;
    }
}