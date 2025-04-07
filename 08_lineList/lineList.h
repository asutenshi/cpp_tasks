#ifndef _LINE_LIST_H
#define _LINE_LIST_H

#include "lineListElem.h"
#include <iostream>

using namespace std;

class LineListException{};

template <class T> class LineList
{
    LineListElem<T>* start;
    LineList(const LineList& list);
    LineList operator =(const LineList& list);

    public:
        LineList();
        ~LineList();
        LineListElem<T>* getStart();
        void deleteFirst();
        void deleteAfter(LineListElem<T>* ptr);
        void insertFirst(const T& data);
        void insertAfter(LineListElem<T>* ptr, const T& data);
        T& operator [](int index);
        // template <class U> friend ostream& operator <<(ostream& out, LineList<U>& list);
        friend ostream& operator <<(ostream& out, const LineList<T>& list);
};

template <class T> LineListElem<T>* LineList<T>::getStart()
{
    return start;
}

template <class T> void LineList<T>::deleteFirst()
{
    if (start)
    {
        LineListElem<T>* temp = start->next;
        delete start;
        start = temp;
    } else throw LineListException();
};

template <class T> LineList<T>::LineList()
{
    start = 0;
}

template <class T> LineList<T>::~LineList()
{
    while (start)
    {
        deleteFirst();
    }
}

template <class T> void LineList<T>::insertFirst(const T& data)
{
    LineListElem<T>* second = start;
    start = new LineListElem<T>(data, second);
} 

template <class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr)
{
    if (ptr && ptr->next)
    {
        LineListElem<T>* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    } else throw LineListException();
}

template <class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data)
{
    if (ptr)
    {
        LineListElem<T>* temp = ptr->next;
        ptr->next = new LineListElem<T>(data, temp);
    } else throw LineListException();
}

template <class T> T& LineList<T>::operator [](int index) {
    LineListElem<T>* it = getStart();
    if (index < 0 || it == nullptr)
        throw LineListException();
    for (int i = 0; i < index; i++)
    {
        if (it->getNext() == nullptr)
            throw LineListException();
        it = it->getNext();
    }
    return it->data;
}

// template <class U> ostream& operator <<(ostream& out, LineList<U>& list)
//     {
//         LineListElem<U>* ptr = list.start;
//         if (!ptr)
//             out << "EMPTY";
//         else while (ptr)
//         {
//             out << ptr->getData() << ' ';
//             ptr = ptr->getNext();
//         }
//         return out;
//     }

template <class T> ostream& operator <<(ostream& out, const LineList<T>& list)
{
    {
        LineListElem<T>* ptr = list.start;
        if (!ptr)
            out << "EMPTY";
        else while (ptr)
        {
            out << ptr->getData() << ' ';
            ptr = ptr->getNext();
        }
        return out;
    }
}

#endif