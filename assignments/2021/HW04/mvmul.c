// Credits to Nic Olsen for original creation

#include <stddef.h>
#include <stdlib.h>

#include "mvmul.h"

void mvmul(const double *A, const double *b, double *c,  size_t n) {
    // must allocate memory for c and initialize with zeros
    // before entering mvmul function
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            c[i] += A[i * n + j] * b[j];
        }
    }
}
