#include <stdio.h>

int main() {
  int arrayX[3] = {9, -3, 2};
  printf("content of arrayX: %d  %d  %d\n", arrayX[0], arrayX[1], arrayX[2]);

  int(*pointerZ)[3];  // here's the interesting part
  pointerZ = &arrayX; // this is interesting too; note the "&" operator

  (*pointerZ)[0] = 7;
  (*pointerZ)[1] = -6;
  (*pointerZ)[2] = 5;
  printf("content of arrayX: %d  %d  %d\n", arrayX[0], arrayX[1], arrayX[2]);

  return 0;
}
