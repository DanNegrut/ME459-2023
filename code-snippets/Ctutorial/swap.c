#include <stdio.h>

void swap(int *px, int *py) {
  int temp;
  temp = *px;
  *px = *py;
  *py = temp;
}

int main() {
  int a = 5;
  int b = 6;
  swap(&a, &b);
  printf(" a is now: %d\n b is now: %d\n", a, b);
  return 0;
}
