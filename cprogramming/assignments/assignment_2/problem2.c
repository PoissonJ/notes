#include <stdio.h>
#include <stdlib.h>

void read_array(int array[], int size) {
  //Implement read_array here
}

int main() {
  int array[100];
  int size;
  int i;
  scanf("%d", &size);
  read_array(array, size);
  printf("[");
  for(i=0;i<size-1;i++) {
    printf("%d,", array[i]);
  }
  if(size) {
    printf("%d", array[size-1]);
  }
  printf("]\n");
  return 0;
}
