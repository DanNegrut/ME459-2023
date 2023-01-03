#include <stdint.h>
#include <stdio.h>

int main() {
  printf("Size of uint8_t  (bytes): %zd\n", sizeof(uint8_t));
  printf("Size of int16_t  (bytes): %zd\n", sizeof(int16_t));
  printf("Size of int32_t  (bytes): %zd\n", sizeof(int32_t));
  printf("Size of uint32_t (bytes): %zd\n", sizeof(uint32_t));
  printf("Size of int64_t  (bytes): %zd\n", sizeof(int64_t));

  return 0;
}
