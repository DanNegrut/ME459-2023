#include "matmul.h"
#include <stdlib.h>

void mmul1(const double* A, const double* B, double *C, const size_t n) {
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      C[i * n + j] = 0.0f;
      for (size_t k = 0; k < n; ++k) {
        C[i * n + j] += A[i * n + k] * B[k * n + j];
      }
    }
  }
}