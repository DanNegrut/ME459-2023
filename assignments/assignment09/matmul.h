#ifndef MATMUL_H
#define MATMUL_H

#include <stddef.h>

// Function produces a row major representation of the matrix C = A B.
// The matrices A, B, and C are n by n and represented as 1D arrays.
void mmul1(const double* A, const double* B, double* C, const size_t n);

#endif
