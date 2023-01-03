#include <stdio.h>

int runner() {
  int count = 0;
  count++;
  return count;
}

int runnerWithStaticVar() {
  static int count = 0;
  count++;
  return count;
}

int main() {
  const int someValue = 3; // defining a const var.
  printf("No static first:\n");
  printf("%d \n", runner());
  printf("%d \n", runner());

  printf("Here's the static case:\n");
  printf("%d \n", runnerWithStaticVar());
  printf("%d \n", runnerWithStaticVar());

  printf("Using the const variable:\n");
  printf("%d \n", runnerWithStaticVar() + someValue);

  return 0;
}
