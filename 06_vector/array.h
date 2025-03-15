#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>

const int DEFAULT_CAPACITY = 10;

class ArrayException {};

// TODO: insert(index, vector); + задача иосифа тест эррэей
class Array {
    int* ptr;
    int size, capacity;

    public:
    explicit Array(int startCapacity=DEFAULT_CAPACITY);
    ~Array();
    Array(const Array &arr);
    Array operator =(const Array &arr);
    int& operator [](int index);
    void insert(int elem, int index);
    void insert(int elem);
    void insert(const Array& arr, int index);
    void insert(const Array& arr);
    void increaseCapacity(int newCapacity);
    void remove(int index);
    int getSize() const;
    friend std::ostream& operator <<(std::ostream& out, const Array& arr);
};

#endif