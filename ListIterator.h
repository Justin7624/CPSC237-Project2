#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "CLinkedList.h"

template <typename T>
class ListIterator {
private:
    const CLinkedList<T>& itr;
    typename CLinkedList<T>::template Node<T>* curr;

public:
    ListIterator(const CLinkedList<T>& l);

    void begin();
    bool isEmpty() const;
    bool isFirstNode() const;
    bool isLastNode() const;
    T operator*() const;
    void operator++();
    void operator++(int);
};

#endif
