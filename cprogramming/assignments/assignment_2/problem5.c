#include <stdio.h>
#include <stdlib.h>

void read_array(int size, int numberOfRuns) {
  //Implement read_array here
  int element;
  if (size == 0) {
      printf("[");
  } else {
      scanf("%d", &element);
      read_array(size - 1, numberOfRuns);

      // Last run so do not print the trailing comma
      if (size == numberOfRuns) {
        printf("%d", element);
      } else {
        printf("%d,", element);
      }
  }
}

int main() {
  int size;

  scanf("%d", &size);
  read_array(size, size);
  printf("]\n");
}

