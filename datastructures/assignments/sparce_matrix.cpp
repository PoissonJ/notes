#include <iostream>

// 0 based (0 = 1 column)
int globalNumberOfColumns = 0;

using namespace std;

template <class T>
struct chainNode {
    // data members
    T element;
    T position;
    chainNode<T> *next;

    // constructors come here
    chainNode() {}

    chainNode(const T& position,const T& element) {
        this->element  = element;
        this->position = position;
    }

    chainNode(const T& position, const T& element, chainNode<T>* next) {
        this->element  = element;
        this->position = position;
        this->next     = next;
    }

    chainNode<T>* returnNextIfHasNext() {
        if (this->next != NULL) {
            return this->next;
        } else {
            return this;
        }
    }

};

//template<class T>
//chainNode<T>* returnNextIfHasNext

template <class T>
chainNode<T>* addMatricies(int numberOfRows, chainNode<T>** matrix1, chainNode<T>** matrix2) {
    chainNode<T>* addedMatricies[numberOfRows];
    chainNode<T>* matrix1Node;
    chainNode<T>* matrix2Node;

    chainNode<T>* currentNode;
    chainNode<T>* firstNode;
    chainNode<T>* tempNode;


    // Traverse Rows
    for (int i = 0; i < numberOfRows; i++) {
        int currentPosition = 0;
        matrix1Node = matrix1[i];
        matrix2Node = matrix2[i];

        if (matrix1Node->position == matrix2Node->position) {
            firstNode = new chainNode<T>(currentPosition, matrix1Node->element + matrix2Node->element, NULL);
            currentPosition++;
            matrix1Node = matrix1Node->returnNextIfHasNext();
            matrix2Node = matrix2Node->returnNextIfHasNext();
        } else {
            if (matrix1Node->position < matrix2Node->position) {
                firstNode = matrix1Node;
                currentPosition = matrix1Node->position;
                currentPosition++;
            } else {
                firstNode = matrix2Node;
                currentPosition = matrix2Node->position;
                currentPosition++;
            }
        }

        currentNode = firstNode;

        // Traverse Columns
        while (currentPosition <= globalNumberOfColumns) {
            if (matrix1Node->position == matrix2Node->position && matrix1Node->position == currentPosition) {
                tempNode = new chainNode<T>(currentPosition, matrix1Node->element + matrix2Node->element, NULL);
                currentNode->next = tempNode;
                currentNode = tempNode;
            } else {
                if (matrix1Node->position == currentPosition) {
                    tempNode = new chainNode<T>(currentPosition, matrix1Node->element, NULL);
                    currentNode->next = tempNode;
                    currentNode = tempNode;
                    matrix1Node = matrix1Node->returnNextIfHasNext();
                } else if (matrix2Node->position == currentPosition) {
                    tempNode = new chainNode<T>(currentPosition, matrix2Node->element, NULL);
                    currentNode->next = tempNode;
                    currentNode = tempNode;
                    matrix2Node = matrix2Node->returnNextIfHasNext();
                }
            }

            currentPosition++;
        }

        addedMatricies[i] = firstNode;
        cout<<endl<<"First node of row "<<i<<" is "<<addedMatricies[i]->element<<" at position "<<firstNode->position<<endl;

    }
    return *addedMatricies;
}

/* CHANGE THIS TO SEARCH AND PRINT! */
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

/* Used for debug purposes */
template <class T>
void printMatrix(int numberOfRows, int numberOfColumns, chainNode<T> ** matrix) {
    chainNode<int>* currentNode;

    for (int i = 0; i < numberOfRows; i++) {
        int currentPosition = 0;
        bool printed;
        cout << endl;
        currentNode = matrix[i];
        cout <<endl<<"Current node is "<<currentNode->element<<endl;

        while (currentPosition < numberOfColumns) {
            printed = false;
            if (currentNode->position == currentPosition) {
                cout << " " << currentNode->element;
                printed = true;
            } else {
                cout << " 0";
            }

            if (currentNode->next != NULL && printed) {
                currentNode = currentNode->next;
            }

            currentPosition++;

        }
        cout << endl;
    }
}

template <class T>
void buildMatrix(chainNode<T>** matrix, int numberOfRows) {
    int  numberOfElemInRow, position, value;
    chainNode<T>* currentNode;
    chainNode<T>* tempNode;
    for (int i = 0; i < numberOfRows; i++) {
        numberOfElemInRow = position = value = 0;

        cin >> numberOfElemInRow;

        // Read in first node
        cin >> position;
        cin >> value;

        if (position > globalNumberOfColumns) {
            globalNumberOfColumns = position;
        }

        matrix[i] = new chainNode<T>(position, value, NULL);
        currentNode = matrix[i];

        // Read in the rest of the nodes
        if (numberOfElemInRow > 1) {
            for (int j = 1; j < numberOfElemInRow; j++) {
                cin >> position;
                cin >> value;

                if (position > globalNumberOfColumns) {
                    globalNumberOfColumns = position;
                }

                tempNode = new chainNode<int>(position, value);
                currentNode->next = tempNode;
                tempNode->next = NULL;
                currentNode = tempNode;
            }
        }
    }
}

int main() {
    int numberOfRows;


    /********* Matrix 1 ****************/
    cin >> numberOfRows;
    chainNode<int>* matrix1[numberOfRows];
    buildMatrix(matrix1, numberOfRows);
    /***********************************/

    /********* Matrix 2 ****************/
    cin >> numberOfRows;
    chainNode<int>* matrix2[numberOfRows];
    buildMatrix(matrix2, numberOfRows);
    /***********************************/

    printMatrix(numberOfRows, 3, matrix1);
    cout << endl;
    printMatrix(numberOfRows, 3, matrix2);

    chainNode<int>* addedMatricies[numberOfRows];
    *addedMatricies = addMatricies(numberOfRows, matrix1, matrix2);

    cout << "Global number of columns: " << globalNumberOfColumns << endl;

    printMatrix(numberOfRows, 3, addedMatricies);

    return 0;
}
