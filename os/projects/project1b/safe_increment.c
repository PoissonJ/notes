#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// Status variable for set and get functions. Not used but needed for implemented system call
int status;

void criticalSection(char * fileName, int numberOfLinesToAdd) {
    int counter = 1;
    FILE * incrementFile;
    char buff[1024];
    int lastNumberInFile;

    while (counter <= numberOfLinesToAdd) {

        incrementFile = fopen(fileName, "r+"); // Open file for reading and writing

        /* Find last line */
        while (fgets(buff, 1024,(FILE*)incrementFile)) {
            if (feof(incrementFile)) break;
            lastNumberInFile = atoi(buff);
        }

        fclose(incrementFile);

        /* Computer Number to add */
        int numberToAdd = lastNumberInFile + 1;

        incrementFile = fopen(fileName, "r+"); // Open file for reading and writing

        /* Find last line */
        while (fgets(buff, 1024,(FILE*)incrementFile)) {
            if (feof(incrementFile)) break;
            lastNumberInFile = atoi(buff);
        }

        /* Append number to last line */
        fprintf(incrementFile, "%d\n", numberToAdd);

        /* Close file */
        fclose(incrementFile);
	counter++;
    }
}


int main(int argc, char * argv[]) {
    FILE * configFile;
    FILE * incrementFile;
    char buff0[1024];
    char buff1[1024];
    char buff[1024];
    char fileName[1024];
    int process0 = 0; // First process listed in config file
    int process1 = 0; // Second process listed in config file
    int counter = 1; // Counter for incrementing
    int numberOfLinesToAdd;
    int turn;

    /* Make sure program is run with correct # of arguments */
    if (argc != 4) {
        printf("Incorrect number of arguments\n");
        exit(1);
    }

    /* Extract variables from command line */
    numberOfLinesToAdd = atoi(argv[1]);
    strncpy(fileName, argv[2], 1024);

    /* Determine PIDs */
    pid_t processPID = getpid();

    /* Write PID to configuration file */
    configFile = fopen(argv[3], "a");
    fprintf(configFile, "%d\n", getpid());
    fclose(configFile);

    /* Read values from config file for uniformity
    *  While loop makes sure the file has been written
    *  by both processes
    */
    while (process0 == 0 || process1 == 0) {
        configFile = fopen(argv[3], "r");
        fgets(buff0, 1024, configFile); // Read process id for process 0
        fgets(buff1, 1024, configFile); // Read process id for process 1
        process0 = atoi(buff0);
        process1 = atoi(buff1);
        fclose(configFile);
    }
    if (process0 > process1) {
    	int temp = process0;
	process0 = process1;
	process1 = temp;
    }

    if (process0 == 0 || process1 == 0) {
        printf("ERROR in getting process numbers\n");
        exit(1);
    }

    if (processPID == process0){

            set_sv(1, &status); // Interested

            turn = 1;
            while (get_sv(process1, &status) == 1 &&
	           turn == (get_sv(process0, &status) ^ get_sv(process1, &status))){
		   // busy wait
            }

            criticalSection(fileName, numberOfLinesToAdd);

            set_sv(0, &status); // Not interested
    }
    else {

            set_sv(1, &status); // Interested

            turn = 0;
            while (get_sv(process0, &status) == 1 &&
	           turn == (get_sv(process0, &status) ^ get_sv(process1, &status))){
		   // busy wait
            }

            criticalSection(fileName, numberOfLinesToAdd);

            set_sv(0, &status); // Not interested
        }
}
