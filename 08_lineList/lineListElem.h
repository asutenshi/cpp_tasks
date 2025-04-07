#ifndef _LINE_LIST_ELEM_H
#define _LINE_LIST_ELEM_H

template <class T> class LineList;

template <class T> class LineListElem
{
    T data;
    LineListElem* next;

    public:
        LineListElem(const T& adata, LineListElem* anext);
        const T& getData() const; 
        LineListElem* getNext();
        // template <class U> friend class LineList;
        friend class LineList<T>;
};

template <class T> LineListElem<T>::LineListElem(
    const T& adata, LineListElem* anext)
{
    data = adata;
    next = anext;
}

template <class T> LineListElem<T>* LineListElem<T>::getNext()
{
    return next;
}

template <class T> const T& LineListElem<T>::getData() const {
    return data;
}

#endif