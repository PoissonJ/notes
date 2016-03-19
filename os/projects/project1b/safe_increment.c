#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int counter = 1; // Global counter for each process to increment file
int status; // Status variable for set and get functions. Not used but needed for implemented system call

void increment(int pidOfOtherProcess, int numberOfLinesToAdd, incrementFile) {
	int shared;
	string sharedStr;
	while (counter < numberOfLinesToAdd) {
		set_sv(10, &status); // Interested but not turn
		/* To avoid bitwise operations I check the value of sharred literally */
		do {
			int shared = get_sv(pidOfOtherProcess, &status);
			switch (shared) {
				case 1: sharedStr = "00"; break;
				case 2: sharedStr = "01"; break;
				case 3: sharedStr = "10"; break;
				case 4: sharedStr = "11"; break;
		} while (shared != "01" && shared != "10");
	}
};

int main(int argc, char * argv[]) {
	FILE * configFile;
	FILE * incrementFile;
	char buff0[1024];
	char buff1[1024];
	int process0 = 0; // First process listed in config file
	int process1 = 0; // Second process listed in config file
	int numberOfLinesToAdd;
	int counter = 1; // Counter for incrementing file

	/* Make sure program is run with correct # of arguments */
	if (argc != 4) {
		printf("Incorrect number of arguments\n");
		exit(1);
	}

	/* Extract variables from command line */
	numberOfLinesToAdd = atoi(argv[1]);

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
		sleep(3); // Suspend so child process can write into config file
	} else {
		sleep(2); // Suspend for a short time to let parent write into config
		configFile = fopen(argv[3], "a");
		fprintf(configFile, "%ld\n", (long)idChild);
		fclose(configFile);
	}

	/* Read values from config file for uniformity */
	configFile = fopen(argv[3], "r");
	fgets(buff0, 1024, configFile); // Read process id for process 0
	fgets(buff1, 1024, configFile); // Read process id for process 1
	process0 = atoi(buff0);
	process1 = atoi(buff1);
	fclose(configFile);

	if (process0 == 0 || process1 == 0) {
		printf("ERROR in getting process numbers\n");
		exit(1);
	}
	
	if (idChild == 0)
		printf("INFO: Parent begun incrementing %s safely\n", argv[2]);
	else
		printf("INFO: Child begun incrementing %s safely\n", argv[2]);

	//if (idChild == 0) increment(process1, numberOfLinesToAdd);
	//else increment(process1, numberOfLinesToAdd);

	return 0;
}
