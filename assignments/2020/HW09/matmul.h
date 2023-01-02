#ifndef MATMUL_H
#define MATMUL_H

#include <stddef.h>

// Returns the matrix product C = A * B.
// A and B are 1D arrays representing nxn matrices in row major order.
// The return value is a 1D array representing the nxn matrix product.
double* mmul1(const double* A, const double* B, size_t n);

#endif
