#include <stddef.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

struct node {
	node * left = NULL;
	node * right = NULL;
	char element;
};

int getInorderIndex(char inorderArray[], int start, int end, char element) {
	for (int i = 0; i <= end; i++) {
		if (inorderArray[i] == element) {
			return i;
		}
	}
	exit(-1);  // Problem with input
}

node* constructTree(char * postorderArray, char * inorderArray,
		int iStart, int iEnd, int pStart, int pEnd) {

	if (iStart > iEnd || pStart > pEnd) {
		return NULL;
	}
	char rootElement = postorderArray[pEnd];
	node * rootNode = new node;
	rootNode->element = rootElement;

	if (iStart == iEnd) return rootNode;

	int inorderIndex = getInorderIndex(inorderArray, iStart, iEnd, rootNode->element);
	rootNode->left = constructTree(postorderArray, inorderArray, iStart, inorderIndex - 1,
			pStart, pStart + inorderIndex - (iStart + 1));
	rootNode->right = constructTree(postorderArray, inorderArray, inorderIndex + 1, iEnd,
			pStart + inorderIndex - iStart, pEnd - 1);

	return rootNode;
}

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

int main() {
	int numberOfNodes;

	cin >> numberOfNodes;

	char postorderArray[numberOfNodes];
	char inorderArray[numberOfNodes];

	for (int i = 0; i < numberOfNodes; i++) {
		cin >> postorderArray[i];

	}

	for (int i = 0; i < numberOfNodes; i++) {
		cin >> inorderArray[i];
	}
	node * rootNode = constructTree(postorderArray, inorderArray, 0, numberOfNodes - 1,
			0, numberOfNodes - 1);
	levelOrder(rootNode);
	cout << endl;
}
