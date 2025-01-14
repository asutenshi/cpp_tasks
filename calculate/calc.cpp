#include <iostream>
#include <stdlib.h>

using namespace std;

#define ERROR_DIV_BY_ZERO -2

int calculate(int op1, int op2, int(*func)(int, int));
int summ(int op1, int op2);
int diff(int op1, int op2);
int mult(int op1, int op2);
int divd(int op1, int op2);
int bals(int op1, int op2);
int fastpow(int op1, int op2);


int (*foper[])(int, int) = {
    summ, diff, mult, divd, bals, fastpow
};

int main(void) {
    char coper[] = {'+', '-', '*', '/', '%', '^'};

    int noper = sizeof(coper) / sizeof(coper[0]);

    do {
        char buf[120];
        char *str = buf;
        char *endptr;
        char oper1;
        char oper2;

        cout << "Enter the exprassion (<op1><symbol><op2><symmol><op3>): " << flush;
        cin >> buf;

        int op1, op2, op2;

        op1 = strtod(str, &endptr);
        oper1 = *endptr++;
        op2 = strtod(str = endptr, &endptr);
        oper2 = *endptr++;
        op3 = strtod(str = endptr, &endptr);
        
        cout << op1 << ' ' << oper1 << ' ' << op2 << ' ' << op3 << " = " << endl;

        int i;
        for (i = 0; i < noper; i++)
            if (oper1 == coper[i]) {
                cout << op1 << ' ' << oper1 << ' ' << op2 << " = " << calculate(op1, op2, foper[i]) << endl;
                break;
            }
        if (i == noper)
            cout << "Wrong math symbol: " << oper << endl;
        
    } while(true);

    return 0;
}

int calculate(int op1, int op2, int(*func)(int, int)) {
    return func(op1, op2);
}

int summ(int op1, int op2) { return op1 + op2; }
int diff(int op1, int op2) { return op1 - op2; }
int mult(int op1, int op2) { return op1 * op2; }
int divd(int op1, int op2) {
    if (!op1)
        exit(ERROR_DIV_BY_ZERO);
    return op1 / op2;
}
int bals(int op1, int op2) { return op1 % op2; }
int fastpow(int op1, int op2) {
    if (!op2)
        return 1;
    if (op2 % 2)
        return op1 * fastpow(op1, op2-1);
    else
        return fastpow(op1*op1, op2/2);
}
