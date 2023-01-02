#include <stdio.h>
int main() {
  unsigned int i;
  // bit-AND with 0 turns all bits to 0; then negate their value to get only 1s
  i = ~(i & 0);
  printf("First value of i: %u\n", i);
  i++;
  printf("Value of i after incrementing by 1: %u\n", i);
  return 0;
}
