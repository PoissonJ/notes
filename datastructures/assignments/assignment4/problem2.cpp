#include <stddef.h>
#include <iostream>
#include <queue>

using namespace std;

struct node {
	node * left;
	node * right;
	char element;
};

void levelOrder(node * currentNode) {
	queue<node*> nodeQueue;

	if (currentNode) {
		nodeQueue.push(currentNode);
	}
	while (!nodeQueue.empty()) {
		node * tempNode = nodeQueue.front();
		nodeQueue.pop();
		cout << tempNode->element << " ";

		if (tempNode->left) {
			nodeQueue.push(tempNode->left);
		}

		if (tempNode->right) {
			nodeQueue.push(tempNode->right);
		}
	}
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

		if (leftPosition == 1 && rightPosition == 3) {
			root = i;
		}
	}
levelOrder(&nodeArray[root]);
}
