#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>

int main(int argc, char** argv) {
	assert(argc == 2);
	const int sv = atoi(argv[1]);
	pid_t child;

	child = fork();
	if(child == 0) {
		int status;
		set_sv(sv, &status);
		pause();
	} else {
		sleep(1);
		int status, actual_sv;
		actual_sv = get_sv(child, &status);
		kill(child, SIGKILL);
		assert(actual_sv == sv);
		printf("SV: %d, ASV: %d\n", sv, actual_sv);
	}
	return 0;
}
