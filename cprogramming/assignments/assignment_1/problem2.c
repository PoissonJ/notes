/* Jonathan Poisson
 * COP3275
 * Programming Assignment 1 Problem 2
 *
 *In this problem the user will choose a number between 0 and 100 (exclusive) and
 *we want to write a program that can guess the user’s chosen number.
 *
 *First, the program will print its initial guess. If the guess is correct, the
 *user will enter 0 and program terminates. Otherwise, if user’s chosen number is
 *bigger than the guessed number, the user will enter 1, if user’s chosen number
 *is smaller than the guessed number, the user will enter -1, and the program
 *prints the next guess. This process continues until the program finds the
 *number.
 *
 *You can employ whatever method you want to calculate the next guess, but the
 *program should be able to find the correct number in at most 10 guesses. Note
 *that the user will not lie, or choose a number outside of the given bounds.
*/

#include <stdlib.h>
#include <stdio.h>

int main() {

    // Initialize variables
    int currentGuess = 50, currentInput, previousInput = 0, additionFactorIterator = 0;

    // Initalize addition factors array to pinpoint the user's number
    int additionFactors[4] = {10, 5, 2, 1};

    // Initalize array to hold the user's input and output
    int inputOutputArray[20];

    // Set the first value of the input and output array to 50 because the
    // computer will always guess the value 50 first
    inputOutputArray[0] = 50;

    // Initalize an int to iterate through the input/output array
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

    return 0;
}

