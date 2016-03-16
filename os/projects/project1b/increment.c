#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
        FILE * fp; // File pointer
        char buff[1024];
        int lastNumberInFile;
        int numberOfLinesToAdd;

	if (argc != 3) {
		printf("Incorrect number of arguments\n");
		return 1;
	} else { // argv[1] is number and argv[2] is the file name

                numberOfLinesToAdd = atoi(argv[1]); // Extract argument
                fp = fopen(argv[2], "r+"); // Open file for reading and writing
                while (fgets(buff, 1024,(FILE*)fp)) {
                    if (feof(fp)) break;
                    /*printf("%s", buff);*/
                    lastNumberInFile = atoi(buff);
                }
                for (int i = 0; i < numberOfLinesToAdd; i++) {
                    char str[3]; // Initialize new string to hold int
                    //sprintf(str, "%d\n", lastNumberInFile + (i + 1));
                    fprintf(fp, "%d\n", lastNumberInFile + ( i + 1 )); // Write to file
                }
                return 0;


	}
}
