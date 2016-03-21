#include <stdio.h>

int main() {
    FILE * inputFp;
    FILE * outputFp;
    int b, x, y, z;

    inputFp = fopen("ex6-data.txt", "r");

    while (!feof(inputFp)) {
        fscanf(inputFp, "%d %d %d\n", &b, &x, &y);
        z = x;
        /*if ( ((z ^ y) & (1 << b)) == 1 << b) { printf("Already correct: ");}*/

        /*y = y & (1 << b); // Flip the bth bit of y*/
        if ((y & (1 << b)) == 0) {
            z = x | (1 << b);
        } else {
            z = x & ~(1 << b);
        }

        if ( ((z ^ y) & (1 << b)) == 1 << b) {
            outputFp = fopen("output.txt", "a+");
            fprintf(outputFp, "%d %d\n", z, y);
            fclose(outputFp);
        } else {
            printf("Incorrect\n");
        }
    }

    return 0;
}
