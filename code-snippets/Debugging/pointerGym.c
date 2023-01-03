#include <stdio.h>

int A(int y) {
  y = y + 1;
  return y;
}

void B(int *y) { y = (int *)10; }

void C(int *y) { *y = 6; }

int main(int argc, char *argv[]) {
  int x = 4;

  x = A(x);
  printf("%d\n", x);

  A(x);
  B(&x);
  printf("%d\n", x);

  C(&x);
  printf("%d\n", x);

  return 0;
}
