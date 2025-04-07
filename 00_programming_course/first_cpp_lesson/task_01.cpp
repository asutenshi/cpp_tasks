// task_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//void main()
int main()
{
    char user_name[50]; // тип данных (char) имя переменной (user_name) 
    unsigned short years;
    double y2 = 1.1;
    int b;
    
    b = (int)(y2 + 0.5);

    std::cout << "y2 = " << y2 << '\t' << "b = " << b << '\n';

    //user_name[0] = '0';
    //user_name[1] = '5';
    //user_name[2] = 0;

    //std::cout << user_name << std::endl;
    //std::cout << (int)user_name[0] << std::endl;
    //std::cout << (int)user_name[1] << std::endl;
    //std::cout << (int)user_name[2] << std::endl;
    //std::cout << (int)user_name[52] << std::endl;

    std::cout << "Enter your name:\t";
    std::cin >> user_name;
    std::cout << "How old are you?\t";
    std::cin >> years;

    std::cout << "Hello " << user_name << "!" << std::endl;
    std::cout << "Years = " << years * (1.0/2) << std::endl;

    std::cout << "Hello World!\n";
//    std::cout << "Hello World!" << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
