#include "stdlib.h"
#include "stdio.h"

int main() {
	short int *vals; // it’ll hold some values later on...
	int num_of_vals = 40;
	short int** myPntr;
	myPntr = (short int**)malloc(sizeof(vals) * num_of_vals);

	printf("sizeof(myPntr): %zu\n", sizeof(myPntr));
	printf("sizeof(*myPntr): %zu\n", sizeof(*myPntr));
	printf("sizeof(myPntr[0]): %zu\n", sizeof(myPntr[0]));
	printf("sizeof(**myPntr): %zu\n", sizeof(**myPntr));
	printf("sizeof(*myPntr[0]): %zu\n", sizeof(*myPntr[0]));

	free(myPntr);
	return 0;
}
