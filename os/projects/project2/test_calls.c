#include <unistd.h>
#include <stdio.h>

#define NULL 0
#define BINARY 0
#define MULTIVAUED 1
typedef int semaphore;

int main() {
	printf("0 = FAIL, except on create\n");

	semaphore s = create_semaphore(BINARY, 1);
	printf("Create Semaphore: %d\n", s);


	int returnVal = down(s);
	printf("DOWN Semaphore: %d\n", returnVal);

	printf("Forking...\n");
	int child = fork();

	if (child != 0) { // child
		printf("Child trying DOWN\n");
		returnVal = down(s);
		printf("Child DOWN Semaphore: %d\n", returnVal);
		return 0;
	}

	returnVal = up(s);
	printf("UP Semaphore: %d\n", returnVal);

	s = delete_semaphore(s);
	printf("Delete semaphore: %d\n", s);
	return 0;
}
