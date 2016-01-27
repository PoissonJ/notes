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

template <class T>
void printList(chainNode<T> * currentNode) {
    while (true) {
        if (currentNode->next != NULL) {
            cout << currentNode->element << " ";
            currentNode = currentNode->next;
        } else {
            cout << currentNode->element << endl;
            break;
        }
    }

}

int main() {
    chainNode<int> * first;
    chainNode<int> * currentNode;
    int numberOfElemInitList;
    int numberOfInterLists;
    int step;
    int numberOfElem;

    cin >> numberOfElemInitList;

    // Handle input
    for (int i = 0; i < numberOfElemInitList; i++) {

        if (i == 0) { // First node
            int temp;
            cin >> temp;
            first = new chainNode<int>(temp);
            currentNode = first;
        } else { // Not first node
            int temp;
            cin >> temp;
            currentNode->next = new chainNode<int>(temp);
            currentNode = currentNode->next;
        }
    }

    cin >> numberOfInterLists;

    for (int i = 0; i < numberOfInterLists; i++) {
        // Reset current node to beginning of list
        currentNode = first;

        cin >> step;
        cin >> numberOfElem;

        // Insert new elements into list
        for (int k = 0; k < numberOfElem; k++) {

            // Progress current node. Start at 1 because 1 represents the first
            // element in the list.
            for (int j = 1; j < step; j++) {
                currentNode = currentNode->next;
            }

            // Insert new node
            chainNode<int> * tempNode = currentNode->next;
            int temp;
            cin >> temp;
            currentNode->next = new chainNode<int>(temp);
            currentNode->next->next = tempNode;

            // Move current node to the newly inserted node's next node
            currentNode = currentNode->next->next;
        }
    }

    printList(first);

    return 0;
}
