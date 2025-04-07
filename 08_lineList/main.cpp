#include "LineListElem.h"
#include "lineList.h"
#include <iostream>

using namespace std;

int main(void)
{
    try 
    {
        LineList<int> list; // Указываем, список какого типа
        cout<<"Начало: "<<list<<endl;
        list.insertFirst(10);
        LineListElem<int>* ptr = list.getStart();
        list.insertAfter(ptr, 15);
        list.insertAfter(ptr->getNext(), 12);
        list.insertFirst(7);
        cout<<"Шаг 1: "<<list<<endl;
        cout<<"list[0]="<<list[0]<<endl;
        cout<<"list[1]="<<list[1]<<endl;
        cout<<"list[2]="<<list[2]<<endl;
        cout<<"list[3]="<<list[3]<<endl;
        cout<<"list[4]"<<list[4]<<endl;
        LineList<int> list2;
        cout<<"list2[0]"<<list2[0]<<endl;
    } catch (class LineListException)
    {
        cout << "что-то пошло не так..." << endl;
    }
    return 0;
}