#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Need one argument to play.\n");
    exit(1);
  }
  int arg1 = atoi(argv[1]); // argv[0] is the program name
  int *storageArray = (int *)malloc(arg1 * sizeof(int));

  for (int i = 0; i < arg1; i++) {
    printf("Enter a number:\n");
    scanf("%d", &storageArray[i]);
  }

  int sum = 0;
  for (int i = 0; i < arg1; i++)
    sum += storageArray[i];

  printf("Sum of the numbers entered is: %d\n", sum);

  free(storageArray);
  return 0;
}
