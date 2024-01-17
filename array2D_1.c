#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>

int ** createArray(int Row, int Col)
{
  int ** array2D = malloc(sizeof(int *)* Row);
  if (array2D == NULL)
  {
    printf("Malloc memory failed 1.\n");
    exit(-1);
  }

  for (int i = 0; i<Row; ++i)
  {
    int *tmp = malloc(sizeof(int)*Col);
    if (tmp == NULL)
    {
      printf("Malloc memory failed 2.\n");
      exit(-1);
    }
    array2D[i] = tmp;
  }

  return array2D;
}

void freeArray(int ** array, int Row)
{
  for (int i = 0; i<Row; ++i)
  {
    free(array[i]);
  }
  free(array);
}


int main() {

  int row = 3;
  int col = 4;

  int ** myArray = createArray(row, col);

  for (int i = 0; i<row; ++i)
  {
    for (int j = 0; j<col; ++j)
    {
      myArray[i][j] = i*col + j;
    }
  }

  for (int i = 0; i<row; ++i)
  {
    for (int j = 0; j<col; ++j)
    {
      printf("%d ", myArray[i][j]);
    }
    printf("\n");
  }

  return 0;
}
