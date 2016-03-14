/**
 *  Author: Jonathan Poisson
 *  Email: Poisson.Jonathan777@gmail.com
 *  Project 1 COP3530
**/

#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <regex>
#include <stack>
#include <stdlib.h>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, double> variables;

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
        else if (isalpha(input[0])) // Input is variable
                               { return 4;}
        else return -1; // Input is number
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

    getline(cin, temp);
    stringstream ss(temp);

    ss >> temp;  // Capture first input to determine type of input
    if (temp == "quit") exit(1);
    if (temp == "let") {
        //If the input is a variable, the program will solve for the
        //variable and then input the value into the unordered map
        ss >> variableName;
        ss >> temp; // "="
        variables.insert({variableName, 0});
        while (ss >> temp) {  // Beginning of the expression to store
            inputQueue.push(temp);
        }
        return variableName;
    } else { // Input is an expression
        inputQueue.push(temp);
        while (ss >> temp) {
        inputQueue.push(temp);
        }
    }
    return "";
}

/* Returns true if there are no issues with finding a variable */
template <class T>
bool postfixBuilder(queue<T>& inputQueue, queue<T>& postfixQueue) {
    stack<T> operatorStack;

    while (!inputQueue.empty()) {
        string currentElement = inputQueue.front();
        int precedence = postfixHelper::isOperator(currentElement);

        if (precedence == -1) { // Current string is a number
            postfixQueue.push(currentElement);
        } else if (precedence == 4) { // Current string variable
            auto got = variables.find(currentElement);
            if (got != variables.end()) { // Variable found
                postfixQueue.push(to_string(got->second));
            } else { // Variable not found
                return false;
            }
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
    return true;
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
double postfixSolve(queue<T>& inputQueue) {
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
        return (double)NULL; // <- Lol wut? Go C++!
}


int main() {
    queue<string> inputQueue;
    queue<string> postfixQueue;
    double answer;
    while (1) {
        // Input
        string variableName = inputBuilder(inputQueue);
        // Shunting yard
        bool noProblems = postfixBuilder(inputQueue, postfixQueue);
        if (noProblems) {
            // Calculate
            answer = postfixSolve(postfixQueue);
            if (answer) {
                if (variableName != "") {
                    //auto search = variables.find(variableName);
                    variables[variableName] = answer;
                } else {
                    cout << answer << endl;
                }
            }
        } else {
            cout << "Undeclared-Variable" << endl;
        }
        // Empty queues
        while (!inputQueue.empty()) {
            inputQueue.pop();
        }
        while (!postfixQueue.empty()) {
            postfixQueue.pop();
        }
    }
    return 0;
}
