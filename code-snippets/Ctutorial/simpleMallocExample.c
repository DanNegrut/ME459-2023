#include "stdlib.h"
#include "stdio.h"

int main() {
  short int *vals; // it’ll hold some values later on...
  int num_of_vals = 40;
  vals = (short int *)malloc(sizeof(*vals) * num_of_vals);
  // vals = (short int *)malloc(sizeof(short int) * num_of_vals);

  printf("sizeof(vals): %zu\n", sizeof(vals));
  printf("sizeof(*vals): %zu\n", sizeof(*vals));
  printf("sizeof(vals[0]): %zu\n", sizeof(*vals));

  free(vals);
  return 0;
}
