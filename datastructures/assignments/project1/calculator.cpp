/**
 *  Author: Jonathan Poisson
 *  Email: Poisson.Jonathan777@gmail.com
 *  Project 1 COP3530
**/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

template <class T>
queue<T> inputBuilder(queue<T>& inputQueue) {
    string temp;

    while (cin.peek() != '\n') {
        cin >> temp;
        inputQueue.push(temp);
    }

    return inputQueue;
}

/* Used for debug purposes */
template <class T>
void printQueue(queue<T>& inputQueue) {
    while (!inputQueue.empty()) {
        string temp = inputQueue.front();
        cout << temp << " ";
        inputQueue.pop();
    } cout << endl;
}

int main() {
    queue<string> inputQueue;
    queue<string> postfixQueue;

    // Input
    inputBuilder(inputQueue);
    printQueue(inputQueue);

    // Shunting yard

    // Calculate
    return 0;
}
