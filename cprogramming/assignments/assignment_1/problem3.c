/* Jonathan Poisson
 * COP3275
 * Programming Assignment 1 Problem 3
 *
 * Extend the previous program to let the user continue using the program by
 * choosing another number to be guessed again, after the current number is
 * guessed correctly. In other words, after the user enters 0, instead of
 * terminating the program, it should print:
 *
 *         Do you want to choose another number?  (Yes=1, No=0)
 *
 * If the answer is 0, the program should be terminated, if the
 * answer is 1, the program should start from the beginning and find the newly
 * chosen number. Therefore, the user can continue using the program as many times
 * as s/he wants.
 *
 * A sample run of the program, when the user chooses 51 the first
 * time, 41 the second time, 61 the third time and then exits the program.
*/

#include<stdlib.h>
#include<stdio.h>

void run();

int main() {
    // Initialize variable
    int choice;

    // Run the function to ask determine user's number
    run();

    do {
        printf("Do you want to choose another number? (Yes=1, No=0) ");
        scanf("%d", &choice);

        if (choice == 1) {
            run();
        }
    } while (choice != 0);

    return 0;
}

void run() {
    // Initialize variables
    int currentGuess = 50, currentInput, previousInput = 0, additionFactorIterator = 0;

    // Initalize addition factors array to pinpoint the user's number
    int additionFactors[4] = {10, 5, 2, 1};

    int inputOutputArray[20];
    inputOutputArray[0] = 50;

    int inputOutputArrayIterator = 1;

    do {
        // Print current guess
        printf("%d\n", currentGuess);
        // Accept user input
        scanf("%d", &currentInput);

        // User's number is greater than the current guess
        if (currentInput == 1) {

            // If the previous input was a -1, the current guess is close to
            // the answer and the addition factor need to be a smaller, more
            // accurate number.
            if (previousInput == -1) {

                // Check to make sure that additionFactorIterator will not go
                // out of the bounds of the array

                // Do nothing to avoid out of bounds error
                if (additionFactorIterator == 3) {}

                else {
                    additionFactorIterator++;
                }
            }

            // Update the current guess
            currentGuess += additionFactors[additionFactorIterator];

        // User's number is less than the current guess
        } else if (currentInput == -1) {
            // If the previous input was a 1, the current guess is close to
            // the answer and the addition factor need to be a smaller, more
            // accurate number.
            if (previousInput == 1) {

                // Check to make sure that additionFactorIterator will not go
                // out of the bounds of the array

                // Do nothing to avoid out of bounds error
                if (additionFactorIterator == 3) {}

                else {
                    additionFactorIterator++;
                }
            }

            // Update the current guess
            currentGuess -= additionFactors[additionFactorIterator];
        }

        // Update the input/output array with the current input
        inputOutputArray[inputOutputArrayIterator] = currentInput;

        // Loop through the input/output array to see if the computer has
        // already guessed the value it is thinking of. If the computer has
        // already guessed the value, it will either add or subtract 1 from the
        // value depending on the users input.
        for (int i = 0; i <= inputOutputArrayIterator; i += 2) {
            if (currentGuess == inputOutputArray[i]) {
                currentGuess = currentGuess + inputOutputArray[i + 1];
            }

        }

        // Update the previous input
        previousInput = currentInput;

        // Add the current guess to the input/output array
        inputOutputArray[inputOutputArrayIterator + 1] = currentGuess;

        // Move the input/output array iterator to the next open slot in the
        // array.
        inputOutputArrayIterator += 2;
    } while (currentInput != 0);

}

