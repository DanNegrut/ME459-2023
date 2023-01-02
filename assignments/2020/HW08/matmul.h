// Credits to Nic Olsen for original creation

#ifndef MATMUL_H
#define MATMUL_H

#include <stddef.h>

// Each function produces a row major representation of the matrix C = A B.
// Details on the expected representation and order of operations within the
// function are given in the task2 description. The matrices A, B, and C are n
// by n and represented as 1D arrays.
double* mmul1(const double* A, const double* B, const size_t n);
double* mmul2(const double* A, const double* B, const size_t n);
double* mmul3(const double* A, const double* B, const size_t n);
double* mmul4(const double* A, const double* B, const size_t n);

#endif
