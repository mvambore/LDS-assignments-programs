#include <stdio.h>

int main()
{
  int m=2, n=3, c, d, transpose[10][10];
  
  int matrix[2][3] = {{1,2,3}, 
                      {4,5,6}};
 
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      transpose[d][c] = matrix[c][d];
 
  printf("Transpose of the matrix:\n");
 
  for (c = 0; c < n; c++) {
    for (d = 0; d < m; d++)
      printf("%d\t", transpose[c][d]);
    printf("\n");
  }

  return 0;
}
