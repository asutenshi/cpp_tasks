#ifndef _LINE_LIST_CYCLE_H
#define _LINE_LIST_CYCLE_H

#include "lineListCycleElem.h"
#include <iostream>

using namespace std;

class LineListCycleException{};

template <class T> class LineListCycle
{
    // TODO: Реализовать арифметику указателей
    LineListCycleElem<T>* start;
    LineListCycleElem<T>* end;
    int size;
    LineListCycle(const LineListCycle& list);
    LineListCycle operator =(const LineListCycle& list);

    public:
        LineListCycle();
        ~LineListCycle();
        LineListCycleElem<T>* getStart();
        LineListCycleElem<T>* getEnd();
        void deleteFirst();
        void deleteAfter(LineListCycleElem<T>* ptr);
        void insertFirst(const T& data);
        void insertAfter(LineListCycleElem<T>* ptr, const T& data);
        T& operator [](int index);
        template <class U> friend ostream& operator <<(ostream& out, LineListCycle<U>& list);
        int getSize();
};

template <class T> LineListCycle<T>::LineListCycle()
{
    start = 0;
    size = 0;
    end = 0;
}

template <class T> LineListCycle<T>::~LineListCycle()
{
    while (start)
    {
        // cout << "size = " << getSize() << endl;
        // cout << "start = " << getStart() << endl;
        // cout << "end = " << getEnd() << endl;
        deleteFirst();
    }
}

template <class T> LineListCycleElem<T>* LineListCycle<T>::getStart()
{
    return start;
}

template <class T> LineListCycleElem<T>* LineListCycle<T>::getEnd()
{
    return end;
}

template <class T> int LineListCycle<T>::getSize()
{
    return size;
}

template <class T> void LineListCycle<T>::insertFirst(const T& data)
{
    if (start)
    {
        LineListCycleElem<T>* second = start;
        start = new LineListCycleElem<T>(data, second);       
        end->next = start;
    } else
    {
        start = new LineListCycleElem<T>(data, start);
        start->next = start;
        end = start;
    }
    size++;
} 

template <class T> void LineListCycle<T>::deleteFirst()
{
    if (start)
    {
        if (size == 1)
        {
            delete start;
            start = 0;
            end = 0;
        } else
        {
            LineListCycleElem<T>* temp = start;
            start = start->next;
            delete temp;
            end->next = start;
        }
        size--;
    } else throw LineListCycleException();
}

template <class T> void LineListCycle<T>::deleteAfter(LineListCycleElem<T>* ptr)
{
    if (ptr && ptr->next && size > 1)
    {
        if (ptr == end)
        {
            deleteFirst();
            return;
        }
        LineListCycleElem<T>* temp = ptr->next;
        if (ptr->next == end)
            end = ptr;
        ptr->next = ptr->next->next;
        delete temp;
        size--;
    } else throw LineListCycleException();
}

template <class T> void LineListCycle<T>::insertAfter(LineListCycleElem<T>* ptr, const T& data)
{
    if (ptr)
    {
        LineListCycleElem<T>* temp = ptr->next;
        ptr->next = new LineListCycleElem<T>(data, temp);
        if (ptr == end)
            end = ptr->next;
        size++;
    } else throw LineListCycleException();
}

template <class T> T& LineListCycle<T>::operator [](int index) {
    LineListCycleElem<T>* it = getStart();
    if (index < 0 || it == 0 || index >= size)
        throw LineListCycleException();
    for (int i = 0; i < index; i++)
    {
        it = it->getNext();
    }
    return it->data;
}

template <class U> ostream& operator <<(ostream& out, LineListCycle<U>& list)
    {
        LineListCycleElem<U>* it = list.start;
        int size = list.getSize();
        if (!it)
            out << "EMPTY";
        else for (int i = 0; i < size; i++)
        {
            out << it->getData() << ' ';
            it = it->getNext();
        }
        return out;
    }

#endif