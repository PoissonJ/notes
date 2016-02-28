/**
 *  Author: Jonathan Poisson
 *  Email: Poisson.Jonathan777@gmail.com
 *  Project 1 COP3530
**/

#include <iostream>
#include <cstring>
#include <math.h>
#include <stack>
#include <stdlib.h>
#include <queue>

using namespace std;

/* Struct to help with postfixFunctions */
struct postfixHelper {
    /* Returns precedence if input is operator, otherwise returns -1 */
    static int isOperator(string input) {
        if (input == "(")      {return 0;}
        else if (input == ")") {return 0;}
        else if (input == "^") {return 3;}
        else if (input == "*") {return 2;}
        else if (input == "/") {return 2;}
        else if (input == "+") {return 1;}
        else if (input == "-") {return 1;}
        else { return -1;} // Input is a number TODO: Add support for variables above
    }
    static bool isLeftAssociative(string input) {
        if (input == "*" || input == "/" ||
            input == "+" || input == "-") return true;
        else return false;
    }
};

template <class T>
void inputBuilder(queue<T>& inputQueue) {
    string temp;

    while (cin.peek() != '\n') {
        cin >> temp;
        inputQueue.push(temp);
    }
}

template <class T>
void postfixBuilder(queue<T>& inputQueue, queue<T>& postfixQueue) {
    stack<T> operatorStack;

    while (!inputQueue.empty()) {
        string currentElement = inputQueue.front();
        int precedence = postfixHelper::isOperator(currentElement);

        if (precedence == -1) { // Current string is a number
            postfixQueue.push(currentElement);
        } else { // Current string is not a number

            if (operatorStack.empty()) {
                operatorStack.push(currentElement);
            } else {

                if (currentElement == "(") operatorStack.push(currentElement);

                else if (currentElement == ")") {
                    while (operatorStack.top() != "(") {
                        postfixQueue.push(operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                } else { // Current element is a normal operator (not a paren)
                    bool leftAssociative = postfixHelper::isLeftAssociative(currentElement);
                    while (!operatorStack.empty()) {
                        int operatorTopPrecedence = postfixHelper::isOperator(operatorStack.top());

                        if ((leftAssociative && precedence <= operatorTopPrecedence) ||
                            (!leftAssociative && precedence < operatorTopPrecedence)) {
                            string temp = operatorStack.top();
                            operatorStack.pop();
                            postfixQueue.push(temp);
                        } else {
                            break;
                        }
                    }
                    operatorStack.push(currentElement);
                }
            }
        }
        inputQueue.pop();
    }
    while (!operatorStack.empty()) {
        postfixQueue.push(operatorStack.top());
        operatorStack.pop();
    }
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

template <class T>
int postfixSolve(queue<T> inputQueue) {
    stack<int> solutionStack;

    while (!inputQueue.empty()) {
        string currentElement = inputQueue.front();
        cout << "Looking at: " << currentElement  << endl;
        if (postfixHelper::isOperator(currentElement) == -1) { // Current element is #
            solutionStack.push(atoi(currentElement.c_str()));
        } else { // Current element is an operator

            int number2 = solutionStack.top();
            solutionStack.pop();
            int number1 = solutionStack.top();
            solutionStack.pop();

            if (currentElement == "^") {
                int temp = pow(number1, number2);
                solutionStack.push(temp);
            } else if (currentElement == "*") {
                int temp = number1 * number2;
                solutionStack.push(temp);
            } else if (currentElement == "/") {
                int temp = number1 / number2;
                solutionStack.push(temp);
            } else if (currentElement == "+") {
                int temp = number1 + number2;
                solutionStack.push(temp);
            } else if (currentElement == "-") {
                int temp = number1 - number2;
                solutionStack.push(temp);
            }
        }
        inputQueue.pop();
    }
    return solutionStack.top();
}


int main() {
    queue<string> inputQueue;
    queue<string> postfixQueue;
    int answer;

    // Input
    inputBuilder(inputQueue);

    // Shunting yard
    postfixBuilder(inputQueue, postfixQueue);

    // Calculate
    answer = postfixSolve(postfixQueue);
    cout << "Answer: " << answer << endl;
    return 0;
}
