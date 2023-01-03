#include <stdio.h>

int main() {
  int foo = 15;
  int *pntr;
  pntr = &foo;

  printf("Address of foo is: %p", &foo);
  printf("\nAddress of foo is: %p", pntr);

  printf("\nValue of foo is: %d", foo);
  printf("\nValue of foo is: %d", *pntr); // dereferencing the pointer here
  printf("\nValue of foo is: %d", *(&foo));

  /* Note: I have used %p for pntr's value as it represents an address*/
  printf("\nValue of pointer pntr is: %p", pntr);
  printf("\nAddress of where pointer is stored: %p\n", &pntr);

  return 0;
}
