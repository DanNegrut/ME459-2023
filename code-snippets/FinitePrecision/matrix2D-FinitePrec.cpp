#include <stdio.h>
#include <stdlib.h>

struct Matrix2D {
  /// 2D matrix stored row-wise in a one dimensional array
  unsigned int height; /// number of rows in matrix
  unsigned int width;  /// number of columns in matrix
  double **pRows;
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Pass 1 for stride 1, pass 2 for large stride\n");
    return 1;
  }
  int option = atoi(argv[1]);

  struct Matrix2D mat2D;
  mat2D.height = 1000; // perhaps you set this based on user input
  mat2D.width = 2000;  // perhaps you set this based on user input

  mat2D.pRows = (double **)malloc(mat2D.height * sizeof(double *));

  unsigned int i;

  for (i = 0; i < mat2D.height; i++)
    mat2D.pRows[i] = (double *)malloc(mat2D.width * sizeof(double));

  // Get meaningful values in this matrix
  unsigned int j;
  for (i = 0; i < mat2D.height; i++)
    for (j = 0; j < mat2D.width; j++)
      mat2D.pRows[i][j] = 2.5 * (i - j);

  // Compute sum of elements
  double sum = 0;
  if (option == 1) {
    for (i = 0; i < mat2D.height; i++)
      for (j = 0; j < mat2D.width; j++)
        sum += mat2D.pRows[i][j];
  } else if (option == 2) {
    for (j = 0; j < mat2D.width; j++)
      for (i = 0; i < mat2D.height; i++)
        sum += mat2D.pRows[i][j];
  } else {
    printf("Bad input option\n");
    return 1;
  }

  printf("The sum of the elements is: %f\n", sum);

  // Don't data anymore, free mem; note that free is used twice
  for (i = 0; i < mat2D.height; i++)
    free(mat2D.pRows[i]);
  free(mat2D.pRows);

  return 0;
}
