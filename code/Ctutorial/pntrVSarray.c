#include "stdlib.h"
#include "stdio.h"

int main() {
    short int* vals; // it’ll hold some values later on...
    int num_of_vals = 3;
    vals = (short int *)malloc(sizeof(short int) * num_of_vals);
    vals[0] = 100;
    vals[1] = 200;
    vals[2] = 300;

    printf("The pointer value: %p\n", vals); // this address of allocated mem
    printf("Print first entry in array: %hi\n", *vals); // this is what's in there
    printf("Print first entry again: %hi\n", vals[0]);
    printf("Print third entry in array: %hi\n", *(vals + 2));
    printf("Print it again: %hi\n", vals[2]);

    free(vals);
    return 0;
}
