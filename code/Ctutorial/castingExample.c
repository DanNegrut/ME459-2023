#include <stdio.h>
#include "stdbool.h"

void nutsKindOf(void *a, bool youBet) {
  if (youBet) {
    int someVal = *(int *)a;
    printf("Value: %d\n", someVal);
  } else {
    float someOtherValue = *(float *)a;
    printf("Value: %f\n", someOtherValue);
  }
}

int main() {
  int aVal = 3;
  float bVal = 9.1f;
  nutsKindOf(&aVal, true);
  nutsKindOf(&bVal, false);
  return 0;
}
