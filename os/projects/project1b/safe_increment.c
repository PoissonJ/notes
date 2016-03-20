#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// Status variable for set and get functions. Not used but needed for implemented system call
int status;

void criticalSection(char * fileName, int counter, int isParent) {
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
    if (isParent) fprintf(incrementFile, "Parent %d\n", counter);
    else fprintf(incrementFile, "child %d\n", counter);
    fprintf(incrementFile, "%d\n", numberToAdd);

    /* Close file */
    fclose(incrementFile);
}


int main(int argc, char * argv[]) {
    FILE * configFile;
    char buff0[1024];
    char buff1[1024];
    char fileName[1024];
    int process0 = 0; // First process listed in config file
    int process1 = 0; // Second process listed in config file
    int parentCounter = 1;
    int childCounter = 1;
    int numberOfLinesToAdd;
    int returnStatus;
    FILE * incrementFile;
    char buff[1024];
    int lastNumberInFile;

    /* Make sure program is run with correct # of arguments */
    if (argc != 4) {
        printf("Incorrect number of arguments\n");
        exit(1);
    }

    /* Extract variables from command line */
    numberOfLinesToAdd = atoi(argv[1]);
    strncpy(fileName, argv[2], 1024);

    /* Determine PIDs */
    pid_t idParent = getpid();
    printf("Process 1: %ld\n", (long)idParent);
    pid_t idChild = fork();
    if (idChild != 0)
            printf("Process 2: %ld\n", (long)idChild);

    /* Write PID to configuration file */
    // Parent process will be process 0
    if (idChild == 0) { // Current process is parent
        configFile = fopen(argv[3], "a");
        fprintf(configFile, "%ld\n", (long)idParent);
        fclose(configFile);
        printf("INFO: Creating and securing safe config file\n");
    } else {
        configFile = fopen(argv[3], "a");
        fprintf(configFile, "%ld\n", (long)idChild);
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


    if (idChild == 0){ // Parent process, process 0
        int shared;
        int lastNumberInFile;
        char flagAndTurn[3];
        flagAndTurn[2] = '\0';
	
        printf("INFO: Parent begun incrementing %s safely\n", argv[2]);

        while (parentCounter <= numberOfLinesToAdd) {
            set_sv(3, &status); // Interested and turn belongs to process 1

            /* To avoid bitwise operations I check the value of shared literally */
            do {
                int shared = get_sv(process1, &status);
		//if (shared != 3) printf("%d\n", shared);
                switch (shared) {
                    case 0: flagAndTurn[0] = '0'; flagAndTurn[1] = '0'; break;
                    case 1: flagAndTurn[0] = '0'; flagAndTurn[1] = '1'; break;
                    case 2: flagAndTurn[0] = '1'; flagAndTurn[1] = '0'; break;
                    case 3: flagAndTurn[0] = '1'; flagAndTurn[1] = '1'; break;
                }
            } while (flagAndTurn[0] == '1' && flagAndTurn[1] == '1');

            criticalSection(fileName, parentCounter, 1);
	    parentCounter++;

            set_sv(1, &status); // No longer interested and turn belongs to process 1
        }
	printf("INFO: Parent done incrementing\n");
	waitpid(process1, &returnStatus, 0);
    }
    else { // Child process, process 1
        int shared;
        int lastNumberInFile;
        char flagAndTurn[3];
        flagAndTurn[2] = '\0';

        printf("INFO: Child begun incrementing %s safely\n", argv[2]);

        while (childCounter <= numberOfLinesToAdd) {
            set_sv(2, &status); // Interested and turn belongs to process 0

            /* To avoid bitwise operations I check the value of shared literally */
            do {
                int shared = get_sv(process0, &status);
                switch (shared) {
                    case 0: flagAndTurn[0] = '0'; flagAndTurn[1] = '0'; break;
                    case 1: flagAndTurn[0] = '0'; flagAndTurn[1] = '1'; break;
                    case 2: flagAndTurn[0] = '1'; flagAndTurn[1] = '0'; break;
                    case 3: flagAndTurn[0] = '1'; flagAndTurn[1] = '1'; break;
                }
            } while (flagAndTurn[0] == '0' && flagAndTurn[1] == '0');

            criticalSection(fileName, childCounter, 0);

            childCounter++;

            set_sv(0, &status);
        }
	printf("INFO: Child done incrementing\n");
	waitpid(process0, &returnStatus, 0);

    }
    return 0;
}
