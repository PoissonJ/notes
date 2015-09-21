#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include "chainNode.cpp"
#include "illegalIndex.cpp"
#include "linearList.cpp"

using namespace std;

template<class T>
class chain : public linearList<T> {
   public:
        // constructors and destructor defined here
        chain();
        ~chain();

        // ADT methods
        bool empty() const {return listSize == 0;}
        int size() const {return listSize;}
        void insert(int theIndex,
                          const T& theElement);
        void printAll() const;
        void printOne(int index) const;
        void erase(int theIndex);
        int getSize();
        void josephusSimulation(vector<int> elementsToInsert, int kthElementRemoved);

    protected:

        bool checkIndex(int theIndex) const;
        T& get(int theIndex) const;
        chainNode<T>* firstNode;
        int indexOf(const T& theElement) const;

        int listSize;
};

template<class T>
chain<T>::chain() {
    // Constructor.

    firstNode = NULL;
    listSize = 0;

}

template<class T>
chain<T>::~chain() {
    // Chain destructor. Delete all nodes
    // in chain.
    while (firstNode != NULL)
    {// delete firstNode
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
int chain<T>::getSize() {
    return this->listSize;
}

template<class T>
bool chain<T>::checkIndex(int theIndex) const {
    // Verify that theIndex is between 0 and
    // listSize - 1.
    try {
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        throw invalid_argument("Bad index");
        return true;
    }
    } catch(invalid_argument& e) {
        cout << "Out of range error: Check Index" << endl;
        return false;
    }
}

template<class T>
T& chain<T>::get(int theIndex) const {
    // Return element whose index is theIndex.
    checkIndex(theIndex);
    // move to desired node
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
       currentNode = currentNode->next;
    return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const {
    // search the chain for theElement

    chainNode<T>* currentNode = firstNode;
    int index = 0;  // index of currentNode

    while (currentNode != NULL &&
            currentNode->element != theElement)
    {
        // move to next node
        currentNode = currentNode->next;
        index++;
    }

    // make sure we found matching element
    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template<class T>
void chain<T>::erase(int theIndex) {

    checkIndex(theIndex);

    chainNode<T>* deleteNode;
    if (theIndex == 0) {
        // remove first node from chain
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else {
        // use p to get to beforeNode
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++) {
            p = p->next;
        }

        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex,
                      const T& theElement) {
    try {
    if (theIndex < 0 || theIndex > listSize) {
        // Throw illegalIndex exception
        ostringstream s;
        s << "The Index = "
        << theIndex << " is out of range";
        //throw illegalIndex(s.str());
        throw invalid_argument("Bad index");
    }


    if (theIndex == 0) {
        // insert at front
        firstNode = new chainNode<T>
                    (theElement, firstNode);
    }
    else {

        // find predecessor of new element
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        // insert after p
        p->next = new chainNode<T>
                    (theElement, p->next);
    }
    } catch(invalid_argument& e) {
        cout << "Out of range error: Insert" << endl;
    }

    listSize++;
}

template<class T>
void chain<T>::printAll() const {
    chainNode<T>* p = this->firstNode;

    for (int i = 0; i < listSize; i++) {
        cout << p->element << " ";
        p = p->next;
    }
    cout << endl;
}

template<class T>
void chain<T>::printOne(int index) const {
    bool goodIndex;

    goodIndex = checkIndex(index);
    if (goodIndex) {

        chainNode<T>* p = this->firstNode;

        for (int i = 0; i < index + 1; i++) {

            if (i == index)  {
                cout << p->element << endl;
            } else {
                p = p->next;
            }
        }
    }
}

template<class T>
void chain<T>::josephusSimulation(vector<int> elementsToInsert, int kthElementRemoved) {

    chainNode<T>* p = this->firstNode;
    int tempIndex;

    for (unsigned i = 0; i < elementsToInsert.size(); i++) {
        cout << "Adding to chain: " << elementsToInsert[i] << endl;
        this->insert(0, elementsToInsert[i]);
    }

    if (this->getSize() == 1) {
        this->printAll();
    }

    else {

        // Print first element removed from list to avoid issues with the zero
        // based index of chain compared to the 1 based kthElementRemoved index
        tempIndex = indexOf(p);
        this->printOne(tempIndex);
        cout << " ";

        p = this->get(kthElementRemoved - 1);

        // Erase this special case
        this->erase(kthElementRemoved - 1);

        while (this->getSize() != 1) {

            for (int i = 0; i < kthElementRemoved; i++) {
                p = p->next;
            }

            cout << p->element << " ";

            this->erase(this->indexOf(p));

        }
    }



}
