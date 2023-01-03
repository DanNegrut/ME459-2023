#include <stdio.h>

void pow_assign(float x, unsigned int exp) {
  float result = 1.0f;
  int i;
  for (i = 0; i < exp; i++) {
    result *=  x;
  }
  x = result;
}

// code snippet that uses above function
int main() {
  float p = 2.0f;
  pow_assign(p, 5);
  printf("Value of p: %f\n", p);
  return 0;
}
