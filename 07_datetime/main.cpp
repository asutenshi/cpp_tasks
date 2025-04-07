#include <iostream>
#include "datetime.h"

using namespace std;

// TODO: ввод через регулярные выражения, вариантивный вывод,
// вывод дня недели.
int main(void) {
    try {
        DateTime dt;
        cin >> dt;
        cout << dt << endl;
        cout << dt+10 << endl;
        cout << dt-20 << endl;
        DateTime dt2(1999, 12, 12);
        cout << (dt - dt2) << endl;
    } catch (DateTimeException& e) {
        cout << "произошла ошибка" << endl;
    }
    return 0;
}