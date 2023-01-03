#include <Windows.h> // need this for timing
#include <stdio.h>
#include <stdlib.h>

struct squashedMatrix {
  /// 2D matrix stored row-wise in a one dimensional array
  unsigned int height; /// number of rows in matrix
  unsigned int width;  /// number of columns in matrix
  double *pMatVals;
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Pass 1 for row-wise, pass 2 for column-wise sum.\n");
    return 1;
  }
  int option = atoi(argv[1]);

  struct squashedMatrix mat1D;

  mat1D.height = 2000; // perhaps you set this based on user input
  mat1D.width = 2000;  // perhaps you set this based on user input
  mat1D.pMatVals =
      (double *)malloc(mat1D.height * mat1D.width * sizeof(double));

  unsigned int i, j;
  for (i = 0; i < mat1D.height; i++)
    for (j = 0; j < mat1D.width; j++)
      mat1D.pMatVals[i * mat1D.width + j] = 1. / (i + j + 1.);

  // Compute sum of elements
  double sum = 0.;
  __int64 ctr1 = 0, ctr2 = 0, freq = 0; // need this for timing
  if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0) {
    if (option == 1) {
      for (i = 0; i < mat1D.height; i++)
        for (j = 0; j < mat1D.width; j++)
          sum += mat1D.pMatVals[i * mat1D.width + j];
    } else if (option == 2) {
      for (j = 0; j < mat1D.width; j++) {
        for (i = 0; i < mat1D.height; i++)
          sum += mat1D.pMatVals[i * mat1D.width + j];
      }
    } else {
      printf("Bad input option\n");
      return 1;
    }
    QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
  }

  printf("The sum of the elements is: %f\n", sum);
  printf("Time spent in microseconds: %f\n", (ctr2 - ctr1) * 1.0 / freq);

  // Done with the matrix; free the mem
  free(mat1D.pMatVals);

  return 0;
}
