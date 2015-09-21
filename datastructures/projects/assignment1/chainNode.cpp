#include <stdio.h>

template <class T>
struct chainNode {
    // data members
    T element;
    chainNode<T> *next;

    // constructors come here
    chainNode() {}

    chainNode(const T& element) {
        this->element = element;
    }

    chainNode(const T& element, chainNode<T>* next) {
        this->element = element;
        this->next = next;
    }
};
