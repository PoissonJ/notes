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
        void josephusSimulation(vector<T> elementsToInsert, int kthElementRemoved);
        T& get(int theIndex) const;

    protected:

        bool checkIndex(int theIndex) const;
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


/* Checks to see if an index of the chain contains an object. Returns a boolean
 * if this test is passed or not.
 *
 * @param theIndex: The index to check
 *
 * @return bool: 'True' is there is an object in the chain at the specified
 * index
 */
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
        cout << "Out of range error" << endl;
        return false;
    }
}


/* Returns an element of an object as a specified index
 *
 * @param theIndex: The index of the object in the chain
 *
 * @return address of T: Location of the element inside the node in the
 * specified object in the chain
 */
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


/* Retrieves the Index of an element contained in a node inside of the chain
 *
 * @param theElement: The element contained in the node you we are finding the
 * index of.
 *
 * @return int: Integer of the index with a node containing the inputed element
 */
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

    // Make sure last node points to the first node //
    chainNode<T>* p = firstNode;

    for (unsigned i = 1; i < listSize; i++) {
        p = p->next;
    }

    if (this->firstNode != p->next) {
        p->next = firstNode;
    }
    //////////////////////////////////////////////
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
        this->firstNode = new chainNode<T>
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
        cout << "Out of range error" << endl;
    }

    listSize++;

    // Make sure last node points to the first node //
    chainNode<T>* p = firstNode;

    for (unsigned i = 1; i < listSize; i++) {
        p = p->next;
    }

    if (this->firstNode != p->next) {
        p->next = firstNode;
    }
    //////////////////////////////////////////////
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
                cout << p->element;
            } else {
                p = p->next;
            }
        }
    }
}

template<class T>
void chain<T>::josephusSimulation(vector<T> elementsToInsert, int kthElementRemoved) {

    int iterator = 1;

    for (unsigned i = 0; i < elementsToInsert.size(); i++) {
        this->insert(0, elementsToInsert[i]);
    }

    chainNode<T>* p = this->firstNode;

    while (this->listSize != 1) {

        while (iterator != kthElementRemoved) {
            p = p->next;
            iterator++;
        }

        printOne(indexOf(p->element));
        cout << " ";
        this->erase(indexOf(p->element));


        iterator = 0;
    }

    if (this->getSize() == 1) {
        this->printAll();
    }
}
