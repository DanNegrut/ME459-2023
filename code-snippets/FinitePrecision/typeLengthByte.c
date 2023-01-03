#include <stdio.h>
#include <stdbool.h>

int main() {
  printf("Size of bool (bytes): %zd\n", sizeof(bool));
  printf("Size of char (bytes): %zd\n", sizeof(char));
  printf("Size of short int (bytes): %zd\n", sizeof(short int));
  printf("Size of int (bytes): %zd\n", sizeof(int));
  printf("Size of unsigned int (bytes): %zd\n", sizeof(unsigned int));
  printf("Size of float (bytes): %zd\n", sizeof(float));
  printf("Size of double (bytes): %zd\n", sizeof(double));

  printf("\nMore exotic types:\n");
  printf("Size of long int (bytes): %zd\n", sizeof(long int));
  printf("Size of long long int (bytes): %zd\n", sizeof(long long int));
  printf("Size of long double (bytes): %zd\n", sizeof(long double));

  return 0;
}
