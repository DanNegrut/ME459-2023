// Credits to Nic Olsen for original creation

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#include "math_utils.h"

#define DIM (1000000000)
#define S2MS (1000)

void FillArray(float* a, size_t count) {
    srand(time(NULL));
    for (size_t i = 0; i < count; i++) {
        a[i] = -1.0 + (2.0 * (float)rand()) / ((float)RAND_MAX);
    }
}

int main(int argc, char* argv[]) {
    // Allocate and populate the array arr
    float* arr = malloc(sizeof(float) * DIM);
    FillArray(arr, DIM);

    clock_t start_sum = clock();
    float sum = Sum(arr, DIM);
    clock_t end_sum = clock();
    double time_sum = ((double)(end_sum - start_sum)) / CLOCKS_PER_SEC * S2MS;

    clock_t start_sum_sines = clock();
    float sum_sines = SumSines(arr, DIM);
    clock_t end_sum_sines = clock();
    double time_sum_sines =
        ((double)(end_sum_sines - start_sum_sines)) / CLOCKS_PER_SEC * S2MS;

    clock_t start_fusion = clock();
    float sum_fusion;
    float sum_sines_fusion;
    Fusion(arr, DIM, &sum_fusion, &sum_sines_fusion);
    clock_t end_fusion = clock();
    double time_fusion =
        ((double)(end_fusion - start_fusion)) / CLOCKS_PER_SEC * S2MS;

    printf("Sum: %0.8f\n", sum);
    printf("SumSines: %0.8f\n", sum_sines);
    printf("Sum Fusion: %0.8f\n", sum_fusion);
    printf("SumSines Fusion: %0.8f\n", sum_sines_fusion);

    printf("Time Sum: %0.8f\n", time_sum);
    printf("Time SumSines: %0.8f\n", time_sum_sines);
    printf("Time Fusion: %0.8f\n", time_fusion);

    free(arr);

    return 0;
}
