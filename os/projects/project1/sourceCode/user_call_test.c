#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int pid = 1000000;
	int status;
	int shared_value;

	shared_value = 25;
	int test = set_sv(shared_value, &status);
	printf("Status after set: %d\n", status);
	int shared_value_check = get_sv(pid, &status);
	printf("PID: %d\n", pid);
	printf("Shared value input: %d\n", shared_value);
	printf("Shared value returned: %d\n", shared_value_check);
	printf("Status after get: %d\n", status);
	return 0;
}
