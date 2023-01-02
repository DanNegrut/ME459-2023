// Credits to Nic Olsen for original creation

#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <stddef.h>
#include <stdlib.h>

// Returns the sum of all entries of arr
// Uses a normal for loop, adding one value at each iteration to an accumulator
float Sum(const float* arr, size_t count);

// Returns the sum of the sine of each entry of arr
// Uses a normal for loop, adding one sine value at each iteration to an
// accumulator
float SumSines(const float* arr, size_t count);

// Returns the sum of entries of arr in the value pointed to by sum and the sum
// of the sines of the entries of arr the value pointed to by sum_sines
// There should only be a single for loop in this function, which calculates
// both quantities simultaneously.
void Fusion(const float* arr, size_t count, float* sum, float* sum_sines);

#endif
