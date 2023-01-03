#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[2] = {266, 5};
  int *p;
  short s;
  printf("This is how many bytes a short uses: %d\n", sizeof(s));

  p = (int *)malloc(sizeof(int) * 3);
  p[2] = arr[1] * 3;

  s = (short)(*(p + 2));

  free(p);
  p = NULL;

  p[0] = 5;
  return 0;
}
