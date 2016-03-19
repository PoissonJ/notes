#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    FILE * fp; // File pointer
    char buff[1024];
    int lastNumberInFile;
    int numberOfLinesToAdd;
    int numberToAdd;
    int counter = 1;

    if (argc != 3) {
            printf("Incorrect number of arguments\n");
            return 1;
    } else { // argv[1] is number and argv[2] is the file name

        numberOfLinesToAdd = atoi(argv[1]); // Extract argument

        /* Open file to initially get the last number before starting loop */
        fp = fopen(argv[2], "r+"); // Open file for reading and writing
        while (fgets(buff, 1024,(FILE*)fp)) {
            if (feof(fp)) break;
            lastNumberInFile = atoi(buff);
        }
        fclose(fp);

        while (counter <= numberOfLinesToAdd) {
            /* Computer Number to add */
            numberToAdd = lastNumberInFile + counter;

            fp = fopen(argv[2], "r+"); // Open file for reading and writing

            /* Find last line */
            while (fgets(buff, 1024,(FILE*)fp)) {
                if (feof(fp)) break;
            }

            /* Append number to last line */
            fprintf(fp, "%d\n", numberToAdd);

            /* Close file */
            fclose(fp);

            counter++;
        }
        return 0;
    }
}
