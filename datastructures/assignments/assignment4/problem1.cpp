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

int main() {
	int leftPosition;
	int rightPosition;
	int numberOfNodes;
	char currentElement;


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

	}

	postOrder(&nodeArray[0]);
	cout << endl;
	inOrder(&nodeArray[0]);
	cout << endl;
	preOrder(&nodeArray[0]);
	cout << endl;

	return 0;
}
