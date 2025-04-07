#include <iostream>
#include <fstream>
using namespace std;

void toBinNumbers();
void fonts();
void sdvig();
void toBinNumbers2();
int toBinNumbers3();
int files();


int main(void)
{
    toBinNumbers3();
    return 1;
}

void toBinNumbers(void) 
{
    cout << "To binary numbers" << endl;
    double x;

    do
    {
        cout << "Enter the number 0<x<1: ";
        cin >> x;
    } while (x <= 0 || x >= 1);

    cout << "binary number: 0.";
    
    for (int i = 0; i < 32; i++)
    {
        x *= 2;
        cout << (int)x;
        x -= (int)x;
        
        if (x <= 1e-8)
            break;
    }
    cout << endl;
}

void fonts(void)
{
    const int FONT_BOLD = 0x1;
    const int FONT_ITALIC = 0x2;
    const int FONT_UNDERLINE = 0x4;

    int some_font = FONT_BOLD | FONT_ITALIC; // теперь some_font будет иметь параметры жирного и наклонного текста
    int another_font;
    // ...
    //if (another_font & FONT_UNDERLINE)
    //{
    //    // ...
    //}
}

void sdvig(void)
{
    int someNumber = 0x36; // 110110
    int anotherNumber = someNumber << 2; // 110110 << 2 = 11011000 (0xc8)
    int negativeNumber = -9076;
    negativeNumber >>= 4; // -9076 / 16 = -568
}

void toBinNumbers2(void)
{
    cout << "Dec number to bin number" << endl;
    int num;

    do
    {
        cout << "Enter the integer dec number > 0: ";
        cin >> num;
    } while (num <= 0);

    cout << "Bin number: ";

    int binValue = 0x40000000; // ставим единицу в 31 бит

    while (binValue > num) binValue >>= 1; // сдвигаем этот 31 бит до момента, пока binValue не станет меньше или равно num
    while (binValue > 0)
    {
        if (num >= binValue)
        {
            cout << '1'; // если числа равны или num больше binValue, то на месте нашей маски будет 1
            num -= binValue;
        }
        else cout << '0';
        binValue >>= 1; // сдвигаем нашу маску на 1 вправо
    }
    cout << endl;
}

int files(void)
{
    ifstream in("in.txt");
    if (!in.is_open())
    {
        cout << "Error: file in.txt is not exist";
        return -1;
    }
    int a, b, c;
    in >> a >> b >> c;
    
    if (in.fail())
    {
        cout << "Error: the numbers aren't read";
        return - 2;
    }
    in.close();
    cout << "Read numbers: " << a << ", " << b << ", " << c << endl;
    
    ofstream out("out.txt");
    if (!out.is_open())
    {
        cout << "Error: can't write file out.txt.";
        return -3;
    }
    out << a << '+' << b << '+' << c << '=' << a + b + c << endl;
    out.close();
    return 0;
}

void binBeforeDot(long long int x, ofstream& out)
{
    long long int num = x;

    long long int binValue = 0x4000000000000000; // ставим единицу в 31 бит

    while (binValue > num) binValue >>= 1; // сдвигаем этот 31 бит до момента, пока binValue не станет меньше или равно num
    while (binValue > 0)
    {
        if (num >= binValue)
        {
            out << '1'; // если числа равны или num больше binValue, то на месте нашей маски будет 1
            num -= binValue;
        }
        else out << '0';
        binValue >>= 1; // сдвигаем нашу маску на 1 вправо
    }
}

void binAfterDot(double n, ofstream& out) 
{
    double x = n;
    
    for (int i = 0; i < 32; i++)
    {
        x *= 2;
        out << (int)x;
        x -= (int)x;
        
        if (x <= 1e-8)
            break;
    }
}

int toBinNumbers3(void)
{
    double number;
    cout << "From dec to bin number" << endl; // << "Enter the dec number: ";
    //cin >> number;

    ifstream in("data.txt");
    if (!in.is_open())
    {
        cout << "Error: file data.txt is not exist";
        return -1;
    }

    in >> number;

    if (in.fail())
    {
        cout << "Error: numbers isn't read";
        return -2;
    }

    in.close();

    long long int beforeDot = (long long int)number;
    double afterDot = number - beforeDot;
    
    ofstream out("answer.txt");
    if (!out.is_open())
    {
        cout << "Error: can't write the file";
        return -3;
    }

    out << number << " - ";
    binBeforeDot(beforeDot, out);
    out << '.';
    binAfterDot(afterDot, out);

    if (out.fail())
    {
        cout << "Error: can't write anwer in the file answer.txt";
        return -4;
    }

    out.close();

    ifstream answerF("answer.txt");
    if (!answerF.is_open())
    {
        cout << "Error: can't open file answer.txt";
        return -5;
    }

    char str[100];
    answerF.getline(str, 100, '\n');
    if (answerF.fail())
    {
        cout << "Error: can't read answer from answer.txt";
        return -6;
    }
    answerF.close();

    cout << str;

    return 0;
}
