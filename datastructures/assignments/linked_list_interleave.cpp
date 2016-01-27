#include <iostream>

using namespace std;

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

int main() {
    return 0;
}
