#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buff1[1024];
    char buff2[1024];
    int firstNumber;
    int secondNumber;

    /* Get first line from input */
    fgets(buff1, 1024, stdin);

    while (!feof(stdin)) {

        /* Get second line from input */
        fgets(buff2, 1024, stdin);

        /* Determine if the numbers are consective and print if not */
        firstNumber = atoi(buff1);
        secondNumber = atoi(buff2);
        if (secondNumber - firstNumber != 1) {
            printf("%d\n", firstNumber);
            printf("%d\n", secondNumber);
        }

        /* Move contents of buff2 to buff1 to not skip any comparisons */
        strncpy(buff1, buff2, 1024);
    }
}
