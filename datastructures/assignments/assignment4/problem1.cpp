#include <stddef.h>
#include <iostream>

using namespace std;

struct node {
	node * left;
	node * right;
	char element;
};

/* Debug purposes */
void printArray(node* nodeArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << nodeArray[i].element << endl;
	}
}

void postOrder(node* currentNode) {
	if (!currentNode) return;
	postOrder(currentNode->left);
	postOrder(currentNode->right);
	cout << currentNode->element << " ";
}

void inOrder(node* currentNode) {
	if (!currentNode) return;
	inOrder(currentNode->left);
	cout << currentNode->element << " ";
	inOrder(currentNode->right);
}

void preOrder(node* currentNode) {
	if (!currentNode) return;
	cout << currentNode->element << " ";
	preOrder(currentNode->left);
	preOrder(currentNode->right);
}

int main(int argc, char **argv) {
	int leftPosition;
	int rightPosition;
	int numberOfNodes;
	char currentElement;

	int root; // Index of root of tree in case the input tries to trick the program

	cin >> numberOfNodes;

	node nodeArray[numberOfNodes];

	for (int i = 0; i < numberOfNodes; i++) {
		cin >> currentElement;
		cin >> leftPosition;
		cin >> rightPosition;

		nodeArray[i].element = currentElement;
		if (leftPosition != -1)
			nodeArray[i].left = &nodeArray[leftPosition];
		else nodeArray[i].left = NULL;

		if (rightPosition != -1)
			nodeArray[i].right = &nodeArray[rightPosition];
		else nodeArray[i].right = NULL;

		if (leftPosition == 1 && rightPosition == 1) {
			root = i;
		}
	}

	postOrder(&nodeArray[root]);
	cout << endl;
	inOrder(&nodeArray[root]);
	cout << endl;
	preOrder(&nodeArray[root]);
	cout << endl;


	return 0;
}
