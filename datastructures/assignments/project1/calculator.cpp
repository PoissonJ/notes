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
#include <unordered_map>

using namespace std;

unordered_map<string, string> variables;

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

/* Returns a sting of the variable name if the user is inputing a variable.
 * Otherwise returns a blank string
 */
template <class T>
string inputBuilder(queue<T>& inputQueue) {
    string temp;
    string variableName;

    while (cin.peek() != '\n') {
        cin >> temp;
        if (temp == "quit") exit(1);
        if (temp == "let") {
            /* If the input is a variable, the program will solve for the
             * variable and then input the value into the unordered map at the
             * end for later use
            */
            cin >> variableName;
            cin >> temp; // "="
            variables.at(variableName) = "";
            while (cin.peek() != '\n') {
                cin >> temp;
                inputQueue.push(temp);
            }
            return variableName;
        } else {
            inputQueue.push(temp);
        }
    }
    return "";
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
double postfixSolve(queue<T> inputQueue) {
    stack<double> solutionStack;

    while (!inputQueue.empty()) {
        string currentElement = inputQueue.front();
        if (postfixHelper::isOperator(currentElement) == -1) { // Current element is #
            solutionStack.push(atof(currentElement.c_str()));
        } else { // Current element is an operator

            double number2 = solutionStack.top();
            solutionStack.pop();
            double number1 = solutionStack.top();
            solutionStack.pop();

            if (currentElement == "^") {
                double temp = pow(number1, number2);
                solutionStack.push(temp);
            } else if (currentElement == "*") {
                double temp = number1 * number2;
                solutionStack.push(temp);
            } else if (currentElement == "/") {
                if (number2 == 0) goto ERROR_DIVISION_BY_ZERO;
                double temp = number1 / number2;
                solutionStack.push(temp);
            } else if (currentElement == "+") {
                double temp = number1 + number2;
                solutionStack.push(temp);
            } else if (currentElement == "-") {
                double temp = number1 - number2;
                solutionStack.push(temp);
            }
        }
        inputQueue.pop();
    }
    return solutionStack.top();

    ERROR_DIVISION_BY_ZERO:
        cout << "Division-By-Zero" << endl;
        return (double)NULL; // <- Lol wut? Go c++!
}


int main() {
    queue<string> inputQueue;
    queue<string> postfixQueue;
    double answer;

    while (1) {
        // Input
        string variableName = inputBuilder(inputQueue);

        // Shunting yard
        postfixBuilder(inputQueue, postfixQueue);

        // Calculate
        answer = postfixSolve(postfixQueue);
        if (answer) {
            if (variableName != "") {
                variables.at(variableName) = answer;
            } else {
                cout << answer << endl;
            }
        }

        // Empty queues
        queue<string> empty;
        swap(inputQueue, empty);
        swap(postfixQueue, empty);

        // Wait for user to enter next expression
        cin.ignore();
    }
    return 0;
}
