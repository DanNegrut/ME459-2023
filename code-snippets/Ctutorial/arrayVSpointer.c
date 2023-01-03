#include <stdio.h>

int main() {
  int arrayX[3];
  printf("size of arrayX: %zu\n", sizeof(arrayX));
  arrayX[0] = 19;
  arrayX[1] = -1;
  arrayX[2] = 83;
  printf("size of arrayX: %zu\n", sizeof(arrayX)); // is the size the same?
  printf("content of arrayX: %d  %d  %d\n", arrayX[0], arrayX[1], arrayX[2]);

  int *pointerY;
  printf("size of pointerY: %zu\n", sizeof(pointerY));
  pointerY = arrayX;       // Here’s the interesting part
  *(pointerY + 1) = -2;    // This is nice pointer arithmetic
  printf("content of arrayX: %d  %d  %d\n", arrayX[0], arrayX[1], arrayX[2]);
  printf("size of pointerY: %zu\n", sizeof(pointerY)); // is the size the same?

  return 0;
}
