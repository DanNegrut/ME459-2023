#include <stdio.h>

int main() {
  const int arr[3] = {2, -3, 8};
  const int *p_arr = arr;
  printf("Address in memory where arr is stored: %p\n", arr);
  printf("Address pointed to by p_arr: %p\n", p_arr);
  int b = *(p_arr + 2) + 12;
  printf("b = %d\n", b);
  return 0;
}
