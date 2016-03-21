#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// Status variable for set and get functions. Not used but needed for implemented system call
int status;

void criticalSection(char * fileName, int counter) {
    FILE * incrementFile;
    char buff[1024];
    int lastNumberInFile;

    incrementFile = fopen(fileName, "r+"); // Open file for reading and writing

    /* Find last line */
    while (fgets(buff, 1024,(FILE*)incrementFile)) {
        if (feof(incrementFile)) break;
        lastNumberInFile = atoi(buff);
    }

    /* Computer Number to add */
    int numberToAdd = lastNumberInFile + 1;

    /* Append number to last line */
    fprintf(incrementFile, "%d\n", numberToAdd);

    /* Close file */
    fclose(incrementFile);
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
    int lastNumberInFile;
    int returnStatus;

    /* Make sure program is run with correct # of arguments */
    if (argc != 4) {
        printf("Incorrect number of arguments\n");
        exit(1);
    }

    /* Extract variables from command line */
    numberOfLinesToAdd = atoi(argv[1]);
    strncpy(fileName, argv[2], 1024);

    /* Determine PIDs */
    pid_t child = fork();
    if (child != 0) // Parent
    	printf("INFO: Process 1: %d\n", getpid());
    else // Child
        printf("INFO: Process 2: %d\n", getpid());

    /* Write PID to configuration file */
    // Parent process will be process 0
    if (child != 0) { // Parent
        printf("INFO: Process 0 writing and securing safe config file\n");
        configFile = fopen(argv[3], "a");
        fprintf(configFile, "%d\n", getpid());
        fclose(configFile);
    } else { // Child
        printf("INFO: Process 1 writing and securing safe config file\n");
        configFile = fopen(argv[3], "a");
        fprintf(configFile, "%d\n", getpid());
        fclose(configFile);
    }

    /* Read values from config file for uniformity
    *  While loop makes sure the file has been written
    *  by both processes
    */
    while (process0 == 0 || process1 == 0 ||
           process0 == process1 || process0 > process1) {
        configFile = fopen(argv[3], "r");
        fgets(buff0, 1024, configFile); // Read process id for process 0
        fgets(buff1, 1024, configFile); // Read process id for process 1
        process0 = atoi(buff0);
        process1 = atoi(buff1);
        fclose(configFile);
    }

    if (process0 == 0 || process1 == 0) {
        printf("ERROR in getting process numbers\n");
        exit(1);
    }


    if (child != 0){ // Parent process, process 0
        int shared;
        int lastNumberInFile;
	
        printf("INFO: Process 0 begun incrementing %s safely\n", argv[2]);

        while (counter <= numberOfLinesToAdd) {
            set_sv(1, &status); // Interested

            while (get_sv(process1, &status) == 1 &&
	           (get_sv(process0, & status) ^ get_sv(process1, &status)) == 1){
		   // busy wait
            }

            criticalSection(fileName, counter);

	    counter++;

            set_sv(0, &status); // Not intested
        }
	printf("INFO: Process 0 done incrementing\n");

    	waitpid(process1, &returnStatus, 0); // Wait for other process to finish
    }
    else { // Child process, process 1
        int shared;
        int lastNumberInFile;

        printf("INFO: Process 1 begun incrementing %s safely\n", argv[2]);

        while (counter <= numberOfLinesToAdd) {
            set_sv(1, &status); // Interested

            while (get_sv(process0, &status) == 1 &&
	           (get_sv(process0, & status) ^ get_sv(process1, &status)) == 0){
		   // busy wait
            }

            criticalSection(fileName, counter);

            counter++;

            set_sv(0, &status); // Not interested
        }
	printf("INFO: Process 1 done incrementing\n");

    	waitpid(process0, &returnStatus, 0); // Wait for other process to finish
    }
    return 0;
}
