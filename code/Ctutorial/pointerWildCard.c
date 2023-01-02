#include <stdio.h>
#include <stdlib.h>

int int_sorter(const void *first_arg, const void *second_arg) {
  // cast the pointers to the right type
  int first = *(int *)first_arg;
  int second = *(int *)second_arg;
  // carry out the comparison
  if (first < second) {
    return -1;
  } else if (first == second) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int array[10];
  int i;
  /* fill array; from largest to smallest */
  for (i = 0; i < 10; ++i) {
    array[i] = 10 - i;
  }
  // get entries rearranged
  qsort(array, 10, sizeof(int), int_sorter);
  for (i = 0; i < 10; ++i) {
    printf("%d\n", array[i]);
  }
}
