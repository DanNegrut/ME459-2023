#include "matmul.h"
#include <stddef.h>
#include <stdlib.h>

double* mmul1(const double* A, const double* B, size_t n) {
    double* C = (double*)calloc(n * n, sizeof(double));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            for (size_t k = 0; k < n; k++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
    return C;
}
