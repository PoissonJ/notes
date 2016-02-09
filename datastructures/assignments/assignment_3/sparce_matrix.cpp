/**
 *  Author: Jonathan Poisson
 *  Email: Poisson.Jonathan777@gmail.com
 *  Assignment 3 COP3530
**/

#include <iostream>
#include <cstring>

using namespace std;

// 0 based (0 = 1 column)
int globalNumberOfColumns = 0;


template <class T>
struct chainNode {
    // data members
    T element;
    T position;
    chainNode<T> *next;

    // constructors come here
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
            for (int j = 2; j <= numberOfElemInRow; j++) {
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

template <class T>
void addMatricies(int numberOfRows, chainNode<T>** matrix1, chainNode<T>** matrix2, chainNode<T>** resultMatrix) {
    chainNode<T>* matrix1Node;
    chainNode<T>* matrix2Node;

    chainNode<T>* currentNode;
    chainNode<T>* firstNode;
    chainNode<T>* tempNode;


    // Traverse Rows
    /******** Grab first node of row *******/
    for (int i = 0; i < numberOfRows; i++) {
        int currentPosition = 0;
        matrix1Node = matrix1[i];
        matrix2Node = matrix2[i];

        // Both matricies start at position at the same position
        if (matrix1Node->position == matrix2Node->position) {
            // Move current position up to the correct position
            while (matrix1Node->position != currentPosition) {
                currentPosition++;
            }
            firstNode = new chainNode<T>(currentPosition, matrix1Node->element + matrix2Node->element, NULL);
            currentPosition++;
            matrix1Node = matrix1Node->returnNextIfHasNext();
            matrix2Node = matrix2Node->returnNextIfHasNext();
        } else {
            // Matrix 1 has a non 0 number before matrix 2
            if (matrix1Node->position < matrix2Node->position) {
                firstNode = matrix1Node;
                currentPosition = matrix1Node->position;
                currentPosition++;
                matrix1Node = matrix1Node->returnNextIfHasNext();
            } else {
            // Matrix 2 has a non 0 number before matrix 1
                firstNode = matrix2Node;
                currentPosition = matrix2Node->position;
                currentPosition++;
                matrix2Node = matrix2Node->returnNextIfHasNext();
            }
        }

        currentNode = firstNode;
    /***************************************/

        // Traverse Columns
        while (currentPosition <= globalNumberOfColumns) {
            if (matrix1Node->position == matrix2Node->position && matrix1Node->position == currentPosition) {
                tempNode = new chainNode<T>(currentPosition, matrix1Node->element + matrix2Node->element, NULL);
                currentNode->next = tempNode;
                currentNode = tempNode;
                matrix1Node = matrix1Node->returnNextIfHasNext();
                matrix2Node = matrix2Node->returnNextIfHasNext();
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

        resultMatrix[i] = firstNode;
    }
}

template <class T>
void searchMatrix(int* searchArray, int length, chainNode<T>** matrix, int rowNum) { // Length is the length of the search array
    int currentSearch;
    chainNode<T>* currentNode;

    // Traverse search array
    for (int i = 0; i < length; i++) {
        // bool firstElement = true; // Used for printing help
        currentSearch = searchArray[i];

        // Traverse matrix
        for (int j = 0; j < rowNum; j++) {
            currentNode = matrix[j];

            while (true) {
                if (currentNode->element == currentSearch) {
                    /* NOTE
                     * I had to take out my smart printing because the
                     * solutions did not use this style of printing and instead
                     * printed with extra spaces at the end :(
                     */
                    //if (firstElement) {
                        //cout << j << " " << currentNode->position;
                        //firstElement = false;
                    //} else { // Not first element so print extra space
                        //cout << " " << j << " " << currentNode->position;
                    //}
                    cout << j << " " << currentNode->position << " ";
                }
                if (currentNode->next == NULL || currentNode->next == 0) {
                    break;
                } else {
                    currentNode = currentNode->returnNextIfHasNext();
                }
            }
        }
        cout << endl;
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

        while (currentPosition <= numberOfColumns) {
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

int main() {
    int numberOfRows;
    int numberOfSearches;

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

    /********* Add Matricies ****************/
    chainNode<int>* addedMatricies[numberOfRows];
    addMatricies(numberOfRows, matrix1, matrix2, addedMatricies);
    /***********************************/

    /********* Handle Searches ****************/
    cin >> numberOfSearches;
    int searchNumberArray[numberOfSearches];

    for (int i = 0; i < numberOfSearches; i++) {
        cin >> searchNumberArray[i];
    }

    searchMatrix(searchNumberArray, numberOfSearches, addedMatricies, numberOfRows);
    /***********************************/
    return 0;
}
