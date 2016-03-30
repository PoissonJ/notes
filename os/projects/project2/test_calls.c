#include <unistd.h>
#include <stdio.h>

int main() {
	// This must be in /usr/src to use the service
	create_seamphore(0, 0); // Must rebuild to get correctly named
	up(0);
	down(0);
	delete_semaphore(0);
	return 0;
}
