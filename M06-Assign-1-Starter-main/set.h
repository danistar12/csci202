#ifndef SET_H
#define SET_H

#include "AVLTree.h"
#include <sstream>

template <typename T>
class Set {
public:
    class Iterator {
    public:
        Iterator(typename AVLTree<T>::Iterator it) : avlIterator(it) {}
        bool hasNext() { return avlIterator.hasNext(); }
        T next() { return avlIterator.next(); }

    private:
        typename AVLTree<T>::Iterator avlIterator;
    };

    void insert(const T& value) {
        avlTree.insert(value);
    }

    bool contains(const T& value) const {
        return avlTree.search(value);
    }

    Iterator begin() const {
        return Iterator(const_cast<AVLTree<T>&>(avlTree).begin());
    }

private:
    AVLTree<T> avlTree;
};

#endif