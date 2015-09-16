/* Jonathan Poisson
 * COP3275
 * Programming Assignment 1 Problem 1
 *
 * We want to write a program that outputs a number to the user, which then gets
 * incremented or decremented based on the user’s input before being printed again
 * until the user terminates the program. In other words after each time the
 * program outputs a number, the user has three choices:
 *
 * 1. Increment the number:
 * the user will enter 1
 * 2. Decrement the number: the user will enter -1
 * 3. Exit the program: the user will enter 0
 *
 * The program will always start from the
 * number 5.
 * A step-by-step explanation of the program is as follows:
 *
 * 1. The program prints 5
 * 2. The program reads a number from the input
 * 3. Based on the input, the program will:
 *     3.1. If the input is 1, increment the previous number, print it and go back to step 2.
 *     3.2. If the input is -1, decrement the
 *     previous number, print it and go back to step 2.
 *     3.3. If the input is 0, exit.
 *
 * The user’s input will be in a way that the number will always stay positive.
*/

#include<stdlib.h>
#include<stdio.h>

#define INCREMENT 1
#define DECREMENT -1
#define EXIT 0

int main() {

     // Initialize variables
    int input, currentNumber = 5;

    do {

        // Print current number
        printf("%d\n", currentNumber);
        // Accept user input
        scanf("%d", &input);

        // Input == 1
        if (input == INCREMENT) {
            currentNumber++;

        // Input ==2
        } else if( input == DECREMENT) {
            currentNumber--;
        }

    // If input is 0, exit the program
    } while (input != 0);

    return 0;

}
