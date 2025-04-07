#ifndef _LINE_LIST_CYCLE_ELEM_H
#define _LINE_LIST_CYCLE_ELEM_H

template <class T> class LineListCycleElem
{
    T data;
    LineListCycleElem* next;

    public:
        LineListCycleElem(const T& adata, LineListCycleElem* anext);
        const T& getData() const; 
        LineListCycleElem* getNext();
        template <class U> friend class LineListCycle;
};

template <class T> LineListCycleElem<T>::LineListCycleElem(
    const T& adata, LineListCycleElem* anext)
{
    data = adata;
    next = anext;
}

template <class T> LineListCycleElem<T>* LineListCycleElem<T>::getNext()
{
    return next;
}

template <class T> const T& LineListCycleElem<T>::getData() const {
    return data;
}

#endif