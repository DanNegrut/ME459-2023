#include<stdio.h>
#include<stdlib.h>

int main()
{
    double *vals;	  //it’ll hold some values later on...
    int num_of_vals = 40;
    // vals = (double*) malloc( sizeof(*vals) * num_of_vals);
    vals = (double*) malloc( sizeof(double) * num_of_vals);

    int dummy = sizeof(vals);
    int dummier = sizeof(*vals);

    free(vals); 
    return 0;
}
